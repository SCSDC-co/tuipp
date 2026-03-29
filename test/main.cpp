#include "tuipp/Console.hpp"
#include "tuipp/print.hpp"

int
main()
{
    tuipp::Console console{};

    tuipp::Console::TerminalSize console_size = console.get_terminal_size();

    tuipp::println("[bold green]Hello, World![reset]");
    tuipp::println(
      "[green]This is green [bold]this is bold and green[/] this is still green[reset]");
    tuipp::println("[blue]Number of files: [reset]", 10, ".");
    tuipp::println("[green]This is green [bold]this is bold and green[reset] this is normal");
    tuipp::println("\\[bold]Hello, World!\\[reset]");

    tuipp::println(console_size.width, "x", console_size.height);

    console << "[bold green]Hello, " << "World!" << "[reset], " << 10 << "." << '\n';

    return 0;
}
