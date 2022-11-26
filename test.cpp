// Author: Ozan Irsoy

#define CATCH_CONFIG_MAIN

#include <iostream>
#include <catch.hpp>
#include <tblr.h>

// clang-format off

TEST_CASE("Basic Layout", "[basic]") {
  SECTION("basic") {
    using namespace tblr;
    Table t;
    t.widths({15, 6, 6, 7})
     .aligns({Left, Center, Center, Center});
    t << "Model" << "Precision" << "Recall" << "F-score" << endr
      << (Cell() << "my" << "Model" << 1) << 0.1 << 0.2 << 0.3 << endr
      << "a model 3" << 0.4 << 0.5 << 0.6 << endr;
    
    std::string expected =
      "Model           Precis Recall F-score\n"
      "                 ion                 \n"
      "myModel1         0.1    0.2     0.3  \n"
      "a model 3        0.4    0.5     0.6  \n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("multiline with space") {
    using namespace tblr;
    Table t;
    t.widths({30, 15})
     .aligns({Left, Left})
     .multiline(Space);
    t << "a function that is continuous everywhere and"
         " differentiable nowhere"
      << "weierstrass function"
      << endr;
    t << "an uncountable set of points that have zero length"
      << "cantor set"
      << endr;
    t << "a continuous curve that covers the entire unit square"
      << "peano curve"
      << endr;

    std::string expected =
      "a function that is continuous  weierstrass    \n"
      "everywhere and differentiable  function       \n"
      "nowhere                                       \n"
      "an uncountable set of points   cantor set     \n"
      "that have zero length                         \n"
      "a continuous curve that        peano curve    \n"
      "covers the entire unit square                 \n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("multiline with space long") {
    using namespace tblr;
    Table t;
    t.widths({2, 10})
     .aligns({Left, Left})
     .multiline(Space);
    t << 1 << "short loooooong" << endr
      << 2 << "short loooooooong" << endr
      << 3 << "short loooooooong short" << endr
      << 4 << "short loooooooong short short" << endr;
    std::string expected =
      "1  short     \n"
      "   loooooong \n"
      "2  short     \n"
      "   loooooooon\n"
      "   g         \n"
      "3  short     \n"
      "   loooooooon\n"
      "   g short   \n"
      "4  short     \n"
      "   loooooooon\n"
      "   g short   \n"
      "   short     \n";

    std::stringstream ss;
    ss << t;
    CHECK(ss.str() == expected);
  }
}

TEST_CASE("Custom Layout", "[custom]") {
  auto layout = tblr::simple_border("| ", " | ", " |", "^", "=", "-", "vV");

  SECTION("single line") {
    tblr::Table t;
    t.widths({15, 5})
     .aligns({tblr::Left, tblr::Right})
     .multiline(tblr::SingleLine)
     .layout(layout);
    t << "Model" << "Precision" << "Recall" << "F-score" << tblr::endr
      << (tblr::Cell() << "my" << "Model" << 1) << 0.1 << 0.2 << 0.3 << tblr::endr
      << "a model 3" << 0.4 << 0.5 << 0.6 << tblr::endr;

    std::string expected =
      "| ^^^^^^^^^^^^^^^ | ^^^^^ | ^^^^^^ | ^^^^^^^ |\n"
      "| Model           | Preci | Recall | F-score |\n"
      "| =============== | ===== | ====== | ======= |\n"
      "| myModel1        |   0.1 | 0.2    | 0.3     |\n"
      "| --------------- | ----- | ------ | ------- |\n"
      "| a model 3       |   0.4 | 0.5    | 0.6     |\n"
      "| vVvVvVvVvVvVvVv | vVvVv | vVvVvV | vVvVvVv |\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("multiline") {
    using namespace tblr;
    Table t;
    t.widths({15, 5})
     .aligns({Left, Right})
     .layout(layout);
    t << "Model" << "Precision" << "Rec\nall\n" << "F-score" << endr
      << (Cell() << "my" << "Model" << 1) << 0.1 << 0.2 << 0.3 << endr
      << "a model 3" << 0.4 << 0.5 << 0.6 << endr;

    std::string expected =
      "| ^^^^^^^^^^^^^^^ | ^^^^^ | ^^^ | ^^^^^^^ |\n"
      "| Model           | Preci | Rec | F-score |\n"
      "|                 |  sion | all |         |\n"
      "| =============== | ===== | === | ======= |\n"
      "| myModel1        |   0.1 | 0.2 | 0.3     |\n"
      "| --------------- | ----- | --- | ------- |\n"
      "| a model 3       |   0.4 | 0.5 | 0.6     |\n"
      "| vVvVvVvVvVvVvVv | vVvVv | vVv | vVvVvVv |\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("extra line") {
    using namespace tblr;
    Table t;
    t.widths({15, 5})
     .aligns({Left, Right})
     .layout(layout);
    t << "Model" << "Precision" << "Rec\nall\n\n" << "F-score" << endr
      << (Cell() << "my" << "Model" << 1) << 0.1 << 0.2 << 0.3 << endr
      << "a model 3" << 0.4 << 0.5 << 0.6 << endr;

    std::string expected =
      "| ^^^^^^^^^^^^^^^ | ^^^^^ | ^^^ | ^^^^^^^ |\n"
      "| Model           | Preci | Rec | F-score |\n"
      "|                 |  sion | all |         |\n"
      "|                 |       |     |         |\n"
      "| =============== | ===== | === | ======= |\n"
      "| myModel1        |   0.1 | 0.2 | 0.3     |\n"
      "| --------------- | ----- | --- | ------- |\n"
      "| a model 3       |   0.4 | 0.5 | 0.6     |\n"
      "| vVvVvVvVvVvVvVv | vVvVv | vVv | vVvVvVv |\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("extra line cr") {
    using namespace tblr;
    Table t;
    t.widths({15, 5})
     .aligns({Left, Right})
     .layout(layout);
    t << "Model" << "Precision" << "Rec\rall\r\r" << "F-score" << endr
      << (Cell() << "my" << "Model" << 1) << 0.1 << 0.2 << 0.3 << endr
      << "a model 3" << 0.4 << 0.5 << 0.6 << endr;

    std::string expected =
      "| ^^^^^^^^^^^^^^^ | ^^^^^ | ^^^ | ^^^^^^^ |\n"
      "| Model           | Preci | Rec | F-score |\n"
      "|                 |  sion | all |         |\n"
      "|                 |       |     |         |\n"
      "| =============== | ===== | === | ======= |\n"
      "| myModel1        |   0.1 | 0.2 | 0.3     |\n"
      "| --------------- | ----- | --- | ------- |\n"
      "| a model 3       |   0.4 | 0.5 | 0.6     |\n"
      "| vVvVvVvVvVvVvVv | vVvVv | vVv | vVvVvVv |\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("extra line crlf") {
    using namespace tblr;
    Table t;
    t.widths({15, 5})
     .aligns({Left, Right})
     .layout(layout);
    t << "Model" << "Precision" << "Rec\r\nall\r\n\r\n" << "F-score" << endr
      << (Cell() << "my" << "Model" << 1) << 0.1 << 0.2 << 0.3 << endr
      << "a model 3" << 0.4 << 0.5 << 0.6 << endr;

    std::string expected =
      "| ^^^^^^^^^^^^^^^ | ^^^^^ | ^^^ | ^^^^^^^ |\n"
      "| Model           | Preci | Rec | F-score |\n"
      "|                 |  sion | all |         |\n"
      "|                 |       |     |         |\n"
      "| =============== | ===== | === | ======= |\n"
      "| myModel1        |   0.1 | 0.2 | 0.3     |\n"
      "| --------------- | ----- | --- | ------- |\n"
      "| a model 3       |   0.4 | 0.5 | 0.6     |\n"
      "| vVvVvVvVvVvVvVv | vVvVv | vVv | vVvVvVv |\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("zero width") {
    using namespace tblr;
    Table t;
    t.widths({0, 5})
     .aligns({Left, Right})
     .layout(layout);
    t << "Model" << "Precision" << "Rec\nall\n\n" << "F-score" << endr
      << (Cell() << "my" << "Model" << 1) << 0.1 << 0.2 << 0.3 << endr
      << "a model 3" << 0.4 << 0.5 << 0.6 << endr;

    std::string expected =
      "| ^^^^^^^^^ | ^^^^^ | ^^^ | ^^^^^^^ |\n"
      "| Model     | Preci | Rec | F-score |\n"
      "|           |  sion | all |         |\n"
      "|           |       |     |         |\n"
      "| ========= | ===== | === | ======= |\n"
      "| myModel1  |   0.1 | 0.2 | 0.3     |\n"
      "| --------- | ----- | --- | ------- |\n"
      "| a model 3 |   0.4 | 0.5 | 0.6     |\n"
      "| vVvVvVvVv | vVvVv | vVv | vVvVvVv |\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }
}

TEST_CASE("Predefined Custom Layout", "[predefined]") {
  using namespace tblr;

  SECTION("markdown") {
    Table t;
    t.layout(markdown());

    t << "things to do" << "when" << endr
      << "give you up" << "never" << endr
      << "let you down" << "never" << endr
      << "run around and desert you" << "never" << endr;

    std::string expected =
      "| things to do              | when  |\n"
      "| ------------------------- | ----- |\n"
      "| give you up               | never |\n"
      "| let you down              | never |\n"
      "| run around and desert you | never |\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("indented list") {
    Table t;
    t.layout(indented_list());

    t << "things to do" << "when" << endr
      << "give you up" << "never" << endr
      << "let you down" << "never" << endr
      << "run around and desert you" << "never" << endr;

    std::string expected =
      "  things to do                when \n"
      "  give you up                 never\n"
      "  let you down                never\n"
      "  run around and desert you   never\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("one column") {
    Table t;
    t.layout(markdown());

    t << "things to do" << endr
      << "give you up" << endr
      << "let you down" << endr
      << "run around and desert you" << endr;

    std::string expected =
      "| things to do              |\n"
      "| ------------------------- |\n"
      "| give you up               |\n"
      "| let you down              |\n"
      "| run around and desert you |\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }

  SECTION("latex") {
    Table t;
    t.layout(latex()).aligns({Left, Right});

    t << "things to do" << "when" << endr
      << "give you up" << "never" << endr
      << "let you down" << "never" << endr
      << "run around and desert you" << "never" << endr;
    std::string expected =
      "\\begin{tabular}{lr}\n"
      "\\hline\n"
      "things to do              &  when \\\\\n"
      "\\hline\n"
      "give you up               & never \\\\\n"
      "let you down              & never \\\\\n"
      "run around and desert you & never \\\\\n"
      "\\hline\n"
      "\\end{tabular}\n";

    std::stringstream ss;
    t.print(ss);
    CHECK(ss.str() == expected);
  }
}

void check(const tblr::Table& t, const std::string& expected) {
  std::stringstream ss;
  ss << t;
  CHECK(ss.str() == expected);
}

TEST_CASE("Edge Cases", "[edge]") {
  using namespace tblr;
  Table t;

  SECTION("empty table") {
    check(t, "");
  }

  SECTION("multiple print") {
    t.widths({15, 6, 6, 7})
     .aligns({Left, Center, Center, Center});
    t << "Model" << "Precision" << "Recall" << "F-score" << endr
      << (Cell() << "my" << "Model" << 1) << 0.1 << 0.2 << 0.3 << endr
      << "a model 3" << 0.4 << 0.5 << 0.6 << endr;
    
    std::string expected =
      "Model           Precis Recall F-score\n"
      "                 ion                 \n"
      "myModel1         0.1    0.2     0.3  \n"
      "a model 3        0.4    0.5     0.6  \n";

    for (size_t i = 0; i < 3; i++) { check(t, expected); }
  }

  SECTION("empty column") {
    t.layout(markdown());
    t << endr << endr;

    std::string expected =
      "|  |\n"
      "|  |\n"
      "|  |\n";

    check(t, expected);
  }

  SECTION("newlines only") {
    auto layout = simple_border("|", "|", "|", "^", "=", "-", "v");
    t.layout(layout);
    t.widths({4});
    t << "\n\n" << endr << "\n\n\n\n" << endr;
    std::string expected =
      "|^^^^|\n"
      "|    |\n"
      "|    |\n"
      "|====|\n"
      "|    |\n"
      "|    |\n"
      "|    |\n"
      "|    |\n"
      "|vvvv|\n";
    check(t, expected);
  }

  SECTION("length mismatch") {
    t.layout(markdown());
    t.widths({4})
     .aligns({Right, Left});
    t << "a" << endr
      << "b" << "c" << "d" << endr
      << endr
      << "e" << "f" << endr;
    std::string expected =
      "|    a |\n"
      "| ---- | - | - |\n"
      "|    b | c | d |\n"
      "|  |\n" // observe empty column (mis)alignment
      "|    e | f |\n";
    check(t, expected);
  }

  SECTION("no row ending") {
    t << "a" << "b" << "c";
    // This effectively means that there are no rows in the table:
    // nothing to print
    check(t, "");
  }

  SECTION("table in table") {
    Table mini;
    mini.layout(markdown());
    mini << "a" << "b" << endr
         << "c" << "d" << endr;

    t.layout(extra_space());
    t << mini << mini << endr
      << mini << mini << endr;

    std::string expected =
      "                        \n"
      "  | a | b |  | a | b |  \n"
      "  | - | - |  | - | - |  \n"
      "  | c | d |  | c | d |  \n"
      "                        \n"
      "  | a | b |  | a | b |  \n"
      "  | - | - |  | - | - |  \n"
      "  | c | d |  | c | d |  \n"
      "                        \n";
    check(t, expected);
  }
}
// clang-format on

std::string strip_ansi(const std::string& s) {
  std::string rval;
  size_t begin = 0;
  auto [left, size] = tblr::find_ansi_esc(s);
  while (left != std::string::npos) {
    rval += s.substr(begin, left - begin);
    begin = left + size;
    std::tie(left, size) = tblr::find_ansi_esc(s, begin);
  }
  rval += s.substr(begin);
  return rval;
}

TEST_CASE("ANSI color & styling", "[color]") {
  using namespace tblr;
  const auto green = "\033[1;32m";
  const auto red = "\033[1;31m";
  const auto blue = "\033[1;34m";
  const auto underline = "\033[1;4m";
  const auto clear = "\033[0m";

  auto mlin = GENERATE(Space, Naive, SingleLine);

  Table t;
  t.layout(unicode_box_light());
  t.widths({10, 10, 7}).multiline(mlin);
  // clang-format off
  t << "animal" << "does what" << "when" << endr
    << "dog" << "barks" << "angry" << endr
    << "rooster" << "crows"
                 << (Cell() << green << "in the cool breezy morning" << clear)
                 << endr
    << "computer" << "crashes"
                  << (Cell() << underline << red << "at warm co"
                             << blue << "zy night" << clear)
                  << endr;
  // clang-format on

  SECTION("Text content") {
    Table plain;
    plain.layout(unicode_box_light());
    plain.widths({10, 10, 7}).multiline(mlin);
    // clang-format off
    plain << "animal" << "does what" << "when" << endr
          << "dog" << "barks" << "angry" << endr
          << "rooster" << "crows" << "in the cool breezy morning" << endr
          << "computer" << "crashes" << "at warm cozy night" << endr;
    // clang-format on

    // Check that raw text content of the styled table is the same as plain
    // table
    CHECK(strip_ansi(t) == std::string(plain));
  }

  SECTION("Output") {
    if (mlin == Space) {
      t.aligns({Left, Left, Right});
      std::string expected =
          "┌──────────┬──────────┬───────┐\n"
          "│animal    │does what │   when│\n"
          "├──────────┼──────────┼───────┤\n"
          "│dog       │barks     │  angry│\n"
          "├──────────┼──────────┼───────┤\n"
          "│rooster   │crows     │ [1;32min the[0m│\n"
          "│          │          │   [1;32mcool[0m│\n"
          "│          │          │ [1;32mbreezy[0m│\n"
          "│          │          │[1;32mmorning[0m│\n"
          "├──────────┼──────────┼───────┤\n"
          "│computer  │crashes   │     [1;4m[1;31mat[0m│\n"
          "│          │          │   [1;4m[1;31mwarm[0m│\n"
          "│          │          │   [1;4m[1;31mco[1;34mzy[0m│\n"
          "│          │          │  [1;4m[1;31m[1;34mnight[0m│\n"
          "└──────────┴──────────┴───────┘\n";
      CHECK(expected == std::string(t));
    }
  }
}

// clang-format off
// clang-format on
