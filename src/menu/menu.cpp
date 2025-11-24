// Header to be implemented
#include "./menu.hpp"

// External dependencies
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

void displayMenu()
{
    // The menu entries:
    std::vector<std::string> entries = {
        "Start",
        "Settings",
        "Help",
        "Quit"};

    // Index of the selected menu item:
    int selected = 0;

    // Create the menu component:
    Component menu = Menu(&entries, &selected);

    // Wrap with renderer to add borders and title:
    Component decorated_menu = Renderer(menu, [&]
                                        { return vbox({
                                                     text(" Main Menu ") | bold | center,
                                                     separator(),
                                                     menu->Render() | border,
                                                     separator(),
                                                     text("Selected: " + entries[selected]) | dim,
                                                 }) |
                                                 border; });

    // Create the screen:
    auto screen = ScreenInteractive::TerminalOutput();

    screen.Loop(decorated_menu);
}
