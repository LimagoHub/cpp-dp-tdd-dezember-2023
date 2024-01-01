//
// Created by JoachimWagner on 03.08.2023.
//

#pragma once

#include <memory>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

namespace de::limago {
    class abstract_node : public std::enable_shared_from_this<abstract_node>{



    public:
        using AbstractNodeShared = std::shared_ptr<abstract_node>;
        using AbstractNodeWeak = std::weak_ptr<abstract_node>;
        using Children = std::vector<AbstractNodeShared>;
        using Stack = std::stack<AbstractNodeShared>;

        class Iterator {
        public:
            using iterator_category = std::bidirectional_iterator_tag;
            using value_type = abstract_node;
            using difference_type = std::ptrdiff_t;
            using pointer = AbstractNodeShared;
            using reference = abstract_node&;

            explicit Iterator(AbstractNodeShared current_node) : current_node_(current_node) {

            }


            auto operator*() const ->abstract_node & {
                return *current_node_;
            }


            auto operator++()-> Iterator& {
                if (find_most_left_child_and_move_iterator_succeeds()) return *this;
                if (find_next_sibling_and_move_iterator_succeeds()) return *this;
                while (find_next_sibling_of_ancestor_and_move_iterator_failes()) {
                    // Empty
                }
                return *this;
            }
            auto operator++(int dummy)->Iterator {
                Iterator old = *this;
                ++(*this);
                return old;
            }

            auto operator--()-> Iterator& {

                if(stack_.size()> 0){
                    auto previous_sibling = current_node_->previous_sibling();
                    if(previous_sibling)
                        current_node_ = previous_sibling;
                    else {
                        current_node_ = stack_.top();
                        stack_.pop();

                    }
                } else {
                    current_node_ = nullptr;
                }
                return *this;
            }
            auto operator--(int dummy)->Iterator {
                Iterator old = *this;
                --(*this);
                return old;
            }


        private:
            AbstractNodeShared current_node_;
            Stack stack_;


            auto find_most_left_child_and_move_iterator_succeeds()-> bool {
                if (current_node_is_leaf()) return false;
                move_to_most_left_child();
                return true;
            }

            auto find_next_sibling_and_move_iterator_succeeds()-> bool {
                if (stack_.empty()) return false;
                return set_next_sibling_succeeds(current_node_);
            }


            auto find_next_sibling_of_ancestor_and_move_iterator_failes()-> bool {
                if (stack_.size() <= 1) return false;

                return !set_next_sibling_succeeds(get_parent());
            }

            auto get_parent() -> AbstractNodeShared {
                auto parent = stack_.top();
                stack_.pop();
                return parent;
            }

            auto set_next_sibling_succeeds(const AbstractNodeShared &node)->bool {
                current_node_ = node->next_sibling(); // Sets current_node to "End" if failes (nullptr)
                return current_node_.get();
            }


            auto move_to_most_left_child()-> void {
                stack_.push(current_node_);
                current_node_ = current_node_->get_children().front();
            }

            [[nodiscard]] auto current_node_is_leaf() const-> bool {
                return current_node_->get_children().empty();
            }

            friend auto operator==(const Iterator &lhs, const Iterator &rhs)-> bool {
                return lhs.current_node_ == rhs.current_node_;
            }

            friend auto operator!=(const Iterator &lhs, const Iterator &rhs)->bool {
                return !(lhs == rhs);
            }

        };


        explicit abstract_node(std::string name = "undef"):name_{std::move(name)}{}
        abstract_node(const abstract_node&) = delete;
        abstract_node& operator = (const abstract_node&) = delete;
        abstract_node(const abstract_node&&) = delete;
        abstract_node& operator = (const abstract_node&&) = delete;

        virtual ~abstract_node() = default;
        auto get_name() const->const std::string & {
            return name_;
        }

        auto set_name(const std::string &name)-> void {
            name_ = name;
        }

        auto get_parent() const-> AbstractNodeWeak {
            return parent_;
        }

        auto set_parent(const AbstractNodeWeak &parent)->void {
            parent_ = parent;
        }

        virtual  auto get_children()const  -> Children {
            static Children dummy{};
            return dummy;
        }
        virtual  auto print(std::ostream& os) const  -> void {
            os << std::string{"name: "} << this->get_name();
        }
        auto begin()-> Iterator
        {
            return Iterator{ shared_from_this() };
        }

        static auto end()-> Iterator
        {
            return Iterator{ nullptr };
        }


        friend auto operator<<(std::ostream &os, const abstract_node &node)-> std::ostream & {
            node.print(os);
            return os;
        }


        auto operator==(const abstract_node &rhs) const-> bool {
            return this == &rhs || (
                   name_ == rhs.name_ &&
                   parent_.lock() == rhs.parent_.lock());
        }

        auto operator!=(const abstract_node &rhs) const-> bool {
            return !(rhs == *this);
        }

    private:
        auto next_sibling() const -> AbstractNodeShared {
            auto siblings = get_parent().lock()->get_children();
            auto position = std::find_if(siblings.begin(), siblings.end(), [this](AbstractNodeShared const &i){return i.get() == this;});
            return ++position != siblings.end() ? *position : nullptr;
        }


        auto previous_sibling() const -> AbstractNodeShared {
            auto siblings = get_parent().lock()->get_children();
            auto position = std::find_if(siblings.begin(), siblings.end(), [this](AbstractNodeShared const &i){return i.get() == this;});
            return position == siblings.begin() ? nullptr: *(--position);
        }


        std::string name_;
        AbstractNodeWeak parent_;

    };
}
