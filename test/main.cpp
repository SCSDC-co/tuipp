#include "tuipp/print.hpp"

int
main()
{
    tuipp::println("[red bold]Hello,[/] [green]World![/]");
    tuipp::println("[green bold]Hello,[/] [cyan]World![/]");

    tuipp::println("[green]This is green [bold]this is bold and green[/] this is still green[/]");

    tuipp::println("\\[bold]Hello, World!\\[/]");

    return 0;
}
