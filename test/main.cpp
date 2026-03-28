#include "tuipp/Console.hpp"
#include "tuipp/print.hpp"

int
main()
{
    tuipp::Console console{};

    tuipp::Console::TerminalSize console_size = console.get_terminal_size();

    tuipp::println("[red bold]Hello,[/] [green]World![/]");
    tuipp::println("[green bold]Hello,[/] [cyan]World![/]");

    tuipp::println("[green]This is green [bold]this is bold and green[/] this is still green[/]");

    tuipp::println("\\[bold]Hello, World!\\[/]");

    tuipp::println(console_size.width, "x", console_size.height);

    return 0;
}
