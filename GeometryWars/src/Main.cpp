//#include "imgui.h"
//#include "imgui-SFML.h"
//
//#include <SFML/Graphics/CircleShape.hpp>
//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/System/Clock.hpp>
//#include <SFML/Window/Event.hpp>

#include"Game.h"
#include"Vec2.hpp"

int main() {

    Vec2<int> vI0 = Vec2<int> ();
    vI0.print(); //0||0

    Vec2<int> vI1 = Vec2<int>(10, 10);
    Vec2<int> vI2 = Vec2<int>(5, 5);
    Vec2<int> vI3 = Vec2<int>(6, 6);

    vI1.print(); //10||10 
    vI1.add(vI2);
    vI1.print(); //15||15
    vI1.sub(vI3);
    vI1.print(); //9||9
    vI1.scale(2.0f); //18||18

    Vec2<int> vI4 = vI1 + vI1;
    vI4.print(); // 36||36

    std::cout << "\n\n";

    Vec2<float> vF0 = Vec2<float>();
    vF0.print(); //0||0
    Vec2<float> vF1 = Vec2<float>(10, 10);
    Vec2<float> vF2 = Vec2<float>(5, 5);

    Vec2<float> vF3 = vF1 + vF2;
    vF3.print();







    /*
    sf::RenderWindow window(sf::VideoMode({ 640, 480 }), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::ShowDemoWindow();

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    */
}