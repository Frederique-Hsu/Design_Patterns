/*!
 *  \file       test_beidge_pattern.cc
 *  \brief      
 *  
 */


#include <catch2/catch_test_macros.hpp>

#include <string>
#include <iostream>

#include "../common_utils/finalize.hpp"
#include "../common_utils/finalize.cpp"

#include "ExtendedAbstraction.hpp"
#include "ConcreteImplementation.hpp"


TEST_CASE("Study and verify how bridge-pattern works", "[Bridge-Pattern]")
{
    SECTION("Demonstrate the client on how to apply the bridge-pattern")
    {
        Implementation* implementor = new ConcreteImplementation_B();
        Abstraction* interface = new ExtendedAbstraction(implementor);
        auto deleter = finalize([&]() {
            delete implementor;
            delete interface;
        });

        auto result = interface->Operation();
        INFO(result);
        
        CHECK(true);
    }
}

SCENARIO("Test scenario for bridge-pattern", "[Bridge-Pattern]")
{
    GIVEN("Define the abstract class Phone and the implementor class Game")
    {
        class Phone;
        class Game;

        class Phone
        {
        public:
            Phone() = default;
            virtual ~Phone() = default;
        private:
            Game* m_game;
        public:
            virtual void setupGame(Game* pgame) = 0;
            virtual void play() = 0;
        protected:
            Game*& game()
            {
                return m_game;
            }
        };

        class Game
        {
        public:
            virtual ~Game() = default;
        public:
            virtual void play() = 0;
        };
        
        WHEN("Concretize the ApplePhone and HuaweiPhone, meanwhile implement the BlackMythWukong and GameForPeace")
        {
            class ApplePhone : public Phone
            {
            public:
                ApplePhone(const char* phone_model_name) : m_model_name{phone_model_name}
                {
                }
            private:
                std::string m_model_name;
            public:
                void setupGame(Game* pgame) override
                {
                    game() = pgame;
                }
                void play() override
                {
                    std::cout << "I am using " << m_model_name << ", ";
                    game()->play();
                }
            };

            class HuaweiPhone : public Phone
            {
            public:
                HuaweiPhone(const char* phone_model_name, const std::string& os_type)
                    : m_model_name{phone_model_name}, m_os_type{os_type}
                {
                }
            private:
                std::string m_model_name;
                std::string m_os_type;
            public:
                virtual void setupGame(Game* pgame) override
                {
                    game() = pgame;
                }
                virtual void play() override
                {
                    std::cout << "I am using " << m_model_name << " (" << m_os_type << "), ";
                    game()->play();
                }
            };

            class BlackMythWukong : public Game
            {
            public:
                BlackMythWukong() = default;
                ~BlackMythWukong() = default;
            public:
                void play() override
                {
                    std::cout << "playing the \"Black Myth : Wu Kong\" 3A PC game..." << std::endl;
                }
            };

            class GameForPeace : public Game
            {
            public:
                GameForPeace() = default;
                ~GameForPeace() = default;
            public:
                virtual void play() override
                {
                    std::cout << "playing the \"Game for Peace\" mobile phone game..." << std::endl;
                }
            };

            THEN("Apply the bridge-pattern to have the client code run")
            {
                Phone* iphone = new ApplePhone("iPhone 16 Pro");
                Game* game = new BlackMythWukong();

                iphone->setupGame(game);
                iphone->play();
                CHECK(true);

                Phone* mate_xt = new HuaweiPhone("Mate-XT 3 fold", "HarmonyOS Next");
                mate_xt->setupGame(game);
                mate_xt->play();
                CHECK(true);

                auto deleter = finalize([&]() {
                    delete iphone;
                    delete game;
                    delete mate_xt;
                });
            }
        }
    }
}