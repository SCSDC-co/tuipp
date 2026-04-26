#include <iostream>
#include <ostream>
#include <vector>

#include "tuipp/Console.hpp"
#include "tuipp/colors.hpp"

int
main()
{
    tuipp::Console console{};
    std::vector<int> vector{ { 1, 2, 3, 4, 5, 6 } };

    tuipp::console_info::TerminalSize console_size = console.terminal_size;

    tuipp::Console::println("Hello, World!");
    tuipp::Console::println("[green]Green text[/]");
    tuipp::Console::println("\\[green]Escaped markup\\[/]");
    tuipp::Console::println("[green bold on gray]Gorgeous text![/] This is normal text!");
    tuipp::Console::println(
      "[green]This is green [bold]this is bold and green[reset] this is normal");
    tuipp::Console::println("[green]Green text [bold]green and bold text[/] still green[/]");

    tuipp::Console::println("[green]It prints iterables: [/]", vector);

    console << "[bold green]Console output![/]" << std::endl << 10 << "." << std::endl;

    tuipp::Console::print_info(true);

    tuipp::Console::println("[dim]Dim text![/]");
    tuipp::Console::println("[reverse]Reverse text![/]");
    tuipp::Console::println("[conceal]Conceal text![/]");
    tuipp::Console::println("[strikethrough]Strikethrough text![/]");

    std::cout << tuipp::colors::blue << "Blue text " << tuipp::colors::on_grey << "cool text"
              << tuipp::colors::reset << " normal text" << std::endl;

    return 0;
}
