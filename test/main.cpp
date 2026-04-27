#include <vector>

#include "tuipp/Console.hpp"
#include "tuipp/widgets/MarkupText.hpp"
#include "tuipp/widgets/Text.hpp"

int
main()
{
    std::vector<int> vector{ { 1, 2, 3, 4, 5, 6 } };

    tuipp::widgets::Text text = tuipp::widgets::Text("Text widget!");
    tuipp::widgets::MarkupText markup_text =
      tuipp::widgets::MarkupText("[bold][green]Markup[/] [blue]text[/][red]![/][/]");

    tuipp::Console::println("Print function:");
    tuipp::Console::println("  [green on grey]Colors![/]");
    tuipp::Console::println("  [underline bold]Styles![/]");
    tuipp::Console::println("  Normal text!");
    tuipp::Console::println("  [[You can escape the markup!]]");
    tuipp::Console::println("  [green]Can print anything: [/]", vector);

    tuipp::Console::println();

    tuipp::Console::println("Widgets:");
    tuipp::Console::println("  ", text);
    tuipp::Console::println("  ", markup_text);

    return 0;
}
