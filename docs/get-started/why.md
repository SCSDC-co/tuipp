---
next: false
---

# Why TUI++?

You might be asking why I created TUI++ when libraries like
[FTXUI](https://github.com/ArthurSonzogni/FTXUI) exists?

While FTXUI is a great library it's harder to write something simple compared to TUI++:

Printing a simple yellow text:

::: code-group

```cpp:line-numbers [FTXUI]
auto document = text("Hello, World!") | color(Color::Yellow);

auto screen = Screen::Create(Dimension::Fit(document), Dimension::Fit(document));
Render(screen, document);
screen.Print();
```

```cpp:line-numbers [TUI++]
tuipp::Console::println("[yellow]Hello, World![/]");
```

:::

---

Printing a multi-color text:

::: code-group

```cpp:line-numbers [FTXUI]
auto document = hflow({
  text("Hello, ") | color(Color::Yellow),
  text("World") | color(Color::Red),
  text("!") | color(Color::green)
});

auto screen = Screen::Create(Dimension::Fit(document), Dimension::Fit(document));
Render(screen, document);
screen.Print();
```

```cpp:line-numbers [TUI++]
tuipp::Console::println("[yellow]Hello, [/][red]World[/][green]![/]");
```

:::

---

TUI++ syntax it's much more concise and shorter, but that doesn't mean you should use it every time,
FTXUI really shine when building interactive TUIs
