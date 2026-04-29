import { defineConfig } from "vitepress";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "TUI++",

  description:
    "A simple TUI library heavily inspired by rich and Spectre.Console",

  cleanUrls: true,

  appearance: "force-dark",

  lastUpdated: true,

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: "Home", link: "/" },
      { text: "Examples", link: "/markdown-examples" },
    ],

    editLink: {
      pattern: "https://github.com/SCSDC-co/tuipp/edit/main/docs/:path",
    },

    sidebar: [
      {
        text: "Getting started",
        collapsed: false,
        items: [
          { text: "Markdown Examples", link: "/markdown-examples" },
          { text: "Runtime API Examples", link: "/api-examples" },
        ],
      },
    ],

    socialLinks: [
      { icon: "github", link: "https://github.com/SCSDC-co/tuipp" },
    ],
  },
});
