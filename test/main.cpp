#include <iostream>
#include <ostream>
#include <vector>

#include "tuipp/Console.hpp"
#include "tuipp/colors.hpp"
#include "tuipp/print.hpp"

int
main()
{
    tuipp::Console console{};
    std::vector<int> vector{ { 1, 2, 3, 4, 5, 6 } };

    tuipp::Console::TerminalSize console_size = console.get_terminal_size();

    tuipp::println("Hello, World!");
    tuipp::println("[green]Green text[/]");
    tuipp::println("\\[green]Escaped markup\\[/]");
    tuipp::println("[green bold on gray]Gorgeous text![/] This is normal text!");
    tuipp::println("[green]This is green [bold]this is bold and green[reset] this is normal");
    tuipp::println("[green]Green text [bold]green and bold text[/] still green[/]");

    tuipp::println("[green]It prints iterables: [/]", vector);

    console << "[bold green]Console output![/]" << std::endl << 10 << "." << std::endl;

    console.print_info(true);
    console.print_info(false);

    std::cout << tuipp::colors::blue << "Blue text " << tuipp::colors::on_grey << "cool text"
              << tuipp::colors::reset << " normal text" << std::endl;

    return 0;
}
