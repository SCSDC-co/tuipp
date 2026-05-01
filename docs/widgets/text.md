---
prev: false
---

# Text

The `Text` widget is used for creating normal text!

::: info

If you want to have multi color text and inline markup syntax use: [MarkupText](/widgets/markup-text.md)

:::

## Examples

::: code-group

```cpp:line-numbers [Plain Text]
auto text = tuipp::widgets::Text("Just plain text!");

tuipp::Console::println(text);
```

```cpp:line-numbers [Colored Text]
auto text = tuipp::widgets::Text("Colored text!");

text.foreground = tuipp::styles::Foreground::GREEN;
text.background = tuipp::styles::Background::GREY;

tuipp::Console::println(text);
```

```cpp:line-numbers [Justification]
auto text = tuipp::widgets::Text("Justified text!");

text.justification = tuipp::styles::Justification::CENTER;

tuipp::Console::println(text);
```

```cpp:line-numbers [Styled]
auto text = tuipp::widgets::Text("Styled text!");

text.foreground    = tuipp::styles::Foreground::GREEN;
text.background    = tuipp::styles::Background::GREY;
text.justification = tuipp::styles::Justification::CENTER;
text.effects       = { tuipp::styles::Effects::BOLD, tuipp::styles::Effects::UNDERLINE };

tuipp::Console::println(text);
```

```cpp:line-numbers [Inside a Panel]
auto panel = tuipp::widgets::Panel(" Panel ");

auto text = tuipp::widgets::Text("Text inside a panel");

panel.add_element(text);

tuipp::Console::println(panel);
```

:::

## Reference

::: details Constructor

```cpp
Text(std::string content,
     styles::Justification justification  = styles::Justification::LEFT,
     styles::Foreground foreground        = styles::Foreground::NONE,
     styles::Background background        = styles::Background::NONE,
     std::vector<styles::Effects> effects = { styles::Effects::NONE })
```

---

**Parameters**

- `content` (`string`)<br>
  The text
- `justification` (`tuipp::styles::Justification`)<br>
  The justification of the text.
- `foreground` (`tuipp::styles::Foreground`)<br>
  The foreground of the text.
- `background` (`tuipp::styles::Background`)<br>
  The background of the text.
- `effects` (`std::vector<styles::Effects>`)<br>
  The effects of the text.

:::

::: details Methods

`render(const int& width)` --> `void`<br>
Renders the component.

---

`get_length(const int& width = 0)` --> `int`<br>
Returns the width of the text.

:::
