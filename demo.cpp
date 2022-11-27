// Author: Ozan Irsoy

#include <iostream>
#include <tblr.h>

int main() {
  using namespace tblr;

  { // Create a table and stream cell by cell. Use endr to end a row.
    Table t;
    // Disabling clang-format because of this bug:
    // https://bugs.llvm.org/show_bug.cgi?id=45018
    // clang-format off
    t << "animal" << "does what" << "when" << endr
      << "dog" << "barks" << "angry" << endr
      << "rooster" << "crows" << "in the morning" << endr
      << "computer" << "crashes" << "at night" << endr;
    // clang-format on
    std::cout << t << std::endl;
  }

  { // Stream multiply into the same cell by using Cell()
    Table t;
    // clang-format off
    t << "animal" << "does what" << "when" << endr;
    // clang-format on
    for (int i = 0; i < 3; i++) {
      t << (Cell() << "dog " << i) << (Cell() << "barks " << i << " times")
        << "angry" << endr;
    }
    std::cout << t << std::endl;
  }

  { // Specify widths and alignments (justifications)
    Table t;
    t.aligns({Left, Center, Right}).widths({10, 10, 0}); // 0 is automatic
    // clang-format off
    t << "animal" << "does what" << "when" << endr
      << "dog" << "barks" << "angry" << endr
      << "rooster" << "crows" << "in the morning" << endr
      << "computer" << "crashes" << "at night" << endr;
    // clang-format on
    std::cout << t << std::endl;
  }

  { // Specify what to do when content does not fit in width
    Table t;
    t.widths({10, 10, 7}).multiline(Space);
    // clang-format off
    t << "animal" << "does what" << "when" << endr
      << "dog" << "barks" << "angry" << endr
      << "rooster" << "crows" << "in the morning" << endr
      << "computer" << "crashes" << "at night" << endr;
    // clang-format on
    std::cout << t << std::endl;

    t.multiline(Naive);
    std::cout << t << std::endl;

    t.multiline(SingleLine);
    std::cout << t << std::endl;
  }

  { // Specify layouts
    Table t;
    t.layout(markdown())
        .aligns({Left, Center, Right})
        .widths({10, 10, 0}); // 0 is automatic
    // clang-format off
    t << "animal" << "does what" << "when" << endr
      << "dog" << "barks" << "angry" << endr
      << "rooster" << "crows" << "in the morning" << endr
      << "computer" << "crashes" << "at night" << endr;
    // clang-format on
    std::cout << t << std::endl;

    t.layout(latex());
    std::cout << t << std::endl;

    t.layout(ascii_box());
    std::cout << t << std::endl;

    t.layout(unicode_box_light());
    std::cout << t << std::endl;
  }

  { // Customize layouts
    auto layout = simple_border(/*left      */ "|| ",
                                /*mid       */ " | ",
                                /*right     */ " ||",
                                /*top       */ "^",
                                /*header mid*/ "-.",
                                /*mid       */ "-",
                                /*bottom    */ "vV");
    Table t;
    t.layout(layout)
        .aligns({Left, Center, Right})
        .widths({10, 10, 0}); // 0 is automatic
    // clang-format off
    t << "animal" << "does what" << "when" << endr
      << "dog" << "barks" << "angry" << endr
      << "rooster" << "crows" << "in the morning" << endr
      << "computer" << "crashes" << "at night" << endr;
    // clang-format on
    std::cout << t << std::endl;
  }

  { // UTF8
    Table t;
    t.layout(markdown());
    // clang-format off
    t << "Op" << "Time" << endr
      << "f(x)" << "3ms" << endr
      << "∂f(x)/∂x" << "4μs" << endr;
    // clang-format on
    std::cout << t << std::endl;
  }

  { // Nesting of tables
    Table t, mini;
    mini.layout(markdown()).aligns({Right, Left}).widths({2, 2});
    // clang-format off
    mini << "T" << "B" << endr
         << "L" << "R" << endr;
    // clang-format on

    t.layout(extra_space());
    t << mini << mini << endr << mini << mini << endr;

    std::cout << t << std::endl;
  }

  { // ANSI color code aware line breaks & width computation
    const auto green = "\033[1;32m";
    const auto red = "\033[1;31m";
    const auto blue = "\033[1;34m";
    const auto underline = "\033[1;4m";
    const auto clear = "\033[0m";

    Table t;
    t.layout(unicode_box_light())
        .widths({10, 10, 7})
        .aligns({Left, Left, Right})
        .multiline(Space);
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
    std::cout << t << std::endl;
  }

  return 0;
}
