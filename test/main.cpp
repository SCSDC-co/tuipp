#include "tuipp/Console.hpp"
#include "tuipp/print.hpp"

int
main()
{
    tuipp::Console console{};

    tuipp::Console::TerminalSize console_size = console.get_terminal_size();

    tuipp::println("[bold green]Hello, World![/]");
    tuipp::println("[green]This is green [bold]this is bold and green[/] this is still green[/]");
    tuipp::println("[blue]Number of files: [/]", 10, ".");
    tuipp::println("[green]This is green [bold]this is bold and green[reset] this is normal");
    tuipp::println("\\[bold]Hello, World!\\[/]");

    tuipp::println(console_size.width, "x", console_size.height);

    console << "[bold green]Hello, " << "World!" << "[/], " << 10 << "." << '\n';

    return 0;
}
