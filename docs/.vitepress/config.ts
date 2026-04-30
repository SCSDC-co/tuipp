import { defineConfig } from "vitepress";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "TUI++",

  description:
    "A simple TUI library heavily inspired by rich and Spectre.Console",

  cleanUrls: true,

  appearance: "force-dark",

  lastUpdated: true,

  base: "tuipp",

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: "Home", link: "/" },
      { text: "Get started", link: "/get-started/install" },
      { text: "Widgets", link: "/widgets/text" },
    ],

    socialLinks: [
      { icon: "github", link: "https://github.com/SCSDC-co/tuipp" },
    ],

    search: {
      provider: "local",
    },

    editLink: {
      pattern: "https://github.com/SCSDC-co/tuipp/edit/main/docs/:path",
    },

    sidebar: [
      {
        text: "Get Started",
        collapsed: false,
        items: [
          {
            text: "How To Install It",
            link: "/get-started/install",
          },
          {
            text: "How To Create Custom Widgets",
            link: "/get-started/how-to-create-custom-widgets",
          },
          {
            text: "Why TUI++?",
            link: "/get-started/why",
          },
        ],
      },
      {
        text: "Widgets",
        collapsed: false,
        items: [
          {
            text: "Text",
            link: "/widgets/text.md",
          },
          {
            text: "Markup Text",
            link: "/widgets/markup-text.md",
          },
          {
            text: "Rule",
            link: "/widgets/rule.md",
          },
        ],
      },
    ],
  },
});
