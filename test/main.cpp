#include "tuipp/Console.hpp"
#include "tuipp/styles/Border.hpp"
#include "tuipp/styles/Foreground.hpp"
#include "tuipp/widgets/MarkupText.hpp"
#include "tuipp/widgets/Panel.hpp"
#include "tuipp/widgets/Text.hpp"

int
main()
{
    auto panel = tuipp::widgets::Panel(" [green]Header[/] ",
                                       tuipp::styles::border::BorderType::ROUNDED,
                                       tuipp::styles::Foreground::GREEN);

    auto text        = tuipp::widgets::Text("text!");
    auto markup_text = tuipp::widgets::MarkupText("[green]markup text![/]");
    auto long_text   = tuipp::widgets::Text("The quick brown fox jumps over the lazy dog.");

    panel.add_element(text);
    panel.add_element(markup_text);
    panel.add_element(long_text);

    tuipp::Console::println(panel);

    return 0;
}
