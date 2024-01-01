//
// Created by JoachimWagner on 06.06.2023.
//

#include "personen_service_impl_test.h"

TEST_P(personen_service_impl_parameter_test, speichern__throws_personen_service_exception) {
    try {

        object_under_test.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), expectedErrorMessage.c_str());
    }
}

TEST_F(personen_service_impl_test, speichern__vorname_too_short__throws_personen_service_exception){
    try {
        person invalidPerson{"j", "doe"};
        object_under_test.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Vorname zu kurz");
    }
}

TEST_F(personen_service_impl_test, speichern__nachname_too_short__throws_personen_service_exception){
    try {
        person invalidPerson{"john", "d"};
        object_under_test.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Nachname zu kurz");
    }
}

TEST_F(personen_service_impl_test, speichern__unerwuenschte_person__throws_personen_service_exception){
    try {
        person blacklistedPerson{"John", "Doe"};
        EXPECT_CALL(blacklistMock, is_blacklisted(blacklistedPerson)).WillOnce(Return(true));
        object_under_test.speichern(blacklistedPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Unerwuenschte Person");
    }
}

TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_blacklist_service__throws_personen_service_exception){
    try {
        person validPerson{};
        EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Throw(std::invalid_argument{"War schon!"}));

        object_under_test.speichern(validPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Fehler im Service");
        auto nested = ex.getNestedException();
        EXPECT_NE(nested, nullptr);
    }
}

TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_repo_service__throws_personen_service_exception){
    try {
        person validPerson{};

        EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(Throw(std::out_of_range{"Upps"}));
        object_under_test.speichern(validPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Fehler im Service");
        auto nested = ex.getNestedException();
        EXPECT_NE(nested, nullptr);
    }
}

TEST_F(personen_service_impl_test, speichern__HappyDay__person_passed_to_repo){

        Sequence s;
        person validPerson{};
        EXPECT_CALL(blacklistMock, is_blacklisted(_)).InSequence(s).WillOnce(Return(false));
        EXPECT_CALL(repoMock, save_or_update(validPerson)).InSequence(s);

        object_under_test.speichern(validPerson);

}

TEST_F(personen_service_impl_test, speichern_overloaded__HappyDay__person_passed_to_repo){


    person captured_person{};
    EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(DoAll(SaveArg<0>(&captured_person)));

    object_under_test.speichern("Max","Mustermann");
    EXPECT_THAT( captured_person.getVorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    EXPECT_THAT(captured_person.getNachname(), AnyOf(Eq("Doe"), Eq("Mustermann")));
    EXPECT_THAT(captured_person.getId(), Not(IsEmpty()));

}

void personen_service_impl_test::SetUp() {
    ON_CALL(blacklistMock, is_blacklisted(_)).WillByDefault(Return(false));
}

INSTANTIATE_TEST_SUITE_P(
        speichern_invalid_names, // Name der Testa frei waehlbar
        personen_service_impl_parameter_test, // Verbindung zur Testklasse
        Values(
                std::make_pair(person{"","Doe"},"Vorname zu kurz" ),
                std::make_pair(person{"J","Doe"},"Vorname zu kurz" ),
                std::make_pair(person{"John",""},"Nachname zu kurz" ),
                std::make_pair(person{"John","D"},"Nachname zu kurz" )
        )
);
