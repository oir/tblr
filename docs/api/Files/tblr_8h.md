---

# tblr.h







## Namespaces

| Name           |
| -------------- |
| **[tblr](api/Namespaces/namespacetblr.md)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[tblr::Endr](api/Classes/classtblr_1_1_endr.md)**  |
| class | **[tblr::Cell](api/Classes/classtblr_1_1_cell.md)**  |
| struct | **[tblr::ColSeparators](api/Classes/structtblr_1_1_col_separators.md)**  |
| class | **[tblr::RowSeparator](api/Classes/classtblr_1_1_row_separator.md)**  |
| class | **[tblr::RowSeparatorFlat](api/Classes/classtblr_1_1_row_separator_flat.md)**  |
| class | **[tblr::RowSeparatorEmpty](api/Classes/classtblr_1_1_row_separator_empty.md)**  |
| class | **[tblr::RowSeparatorColwise](api/Classes/classtblr_1_1_row_separator_colwise.md)**  |
| struct | **[tblr::RowSeparators](api/Classes/structtblr_1_1_row_separators.md)**  |
| struct | **[tblr::Layout](api/Classes/structtblr_1_1_layout.md)**  |
| class | **[tblr::Table](api/Classes/classtblr_1_1_table.md)**  |
| class | **[tblr::LatexHeader](api/Classes/classtblr_1_1_latex_header.md)**  |















## Source code

```cpp
// Author: Ozan Irsoy

#ifndef TBLR_H
#define TBLR_H

#include <algorithm>
#include <cassert>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace tblr {

enum Align : char { Left = 'l', Center = 'c', Right = 'r' };

enum LineSplitter { SingleLine, Naive, Space };

using Row = std::vector<std::string>;

using Widths = std::vector<size_t>;

using Aligns = std::vector<Align>;

class Endr {};
const static Endr endr, endl;

inline bool is_first_byte(const char& c) {
  // https://stackoverflow.com/a/4063229
  return (c & 0xc0) != 0x80;
}

inline size_t len(const std::string& s) {
  return std::count_if(s.begin(), s.end(), is_first_byte);
}

inline std::string
substr(const std::string& s, size_t left = 0, size_t size = -1) {
  auto i = s.begin();
  for (left++; i != s.end() and (left -= is_first_byte(*i)); i++) {}
  auto pos = i;
  for (size++; i != s.end() and (size -= is_first_byte(*i)); i++) {}
  return s.substr(pos - s.begin(), i - pos);
}

std::string normalize_newlines(const std::string& s) {
  std::string rval;
  rval.reserve(s.size());

  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '\r') {
      if (i < (s.size() - 1) and s[i + 1] == '\n') { i++; }
      rval += '\n';
    } else {
      rval += s[i];
    }
  }

  return rval;
}

class Cell {
 private:
  std::stringstream ss_;

 public:
  template <typename T>
  friend Cell& operator<<(Cell& c, const T& x) {
    c.ss_ << x;
    return c;
  }
  template <typename T>
  friend Cell&& operator<<(Cell&& c, const T& x) {
    c.ss_ << x;
    return std::move(c);
  }
  std::string str() const { return ss_.str(); }
};

struct ColSeparators {
  std::string left = "";
  std::string mid = " ";
  std::string right = "";
};

class RowSeparator {
 public:
  virtual void print(std::ostream& out,
                     const Widths& spec_widths,
                     const Widths& widths,
                     const Aligns& aligns) const = 0;

  virtual ~RowSeparator() {}
};

class RowSeparatorFlat : public RowSeparator {
 private:
  std::string sepr_;

 public:
  RowSeparatorFlat(std::string sepr = "") : sepr_(std::move(sepr)) {}

  void print(std::ostream& out,
             const Widths& /*spec_widths*/,
             const Widths& /*widths*/,
             const Aligns& /*aligns*/) const override {
    out << sepr_ << std::endl;
  }
};

class RowSeparatorEmpty : public RowSeparator {
 public:
  void print(std::ostream& /*out*/,
             const Widths& /*spec_widths*/,
             const Widths& /*widths*/,
             const Aligns& /*aligns*/) const override {}
};

class RowSeparatorColwise : public RowSeparator {
 private:
  ColSeparators col_sepr_;
  std::string filler_;

 public:
  RowSeparatorColwise(ColSeparators csep = {}, std::string fill = " ")
      : col_sepr_(std::move(csep)), filler_(std::move(fill)) {
    assert(not filler_.empty());
  }

  void print(std::ostream& out,
             const Widths& spec_widths,
             const Widths& widths,
             const Aligns& /*aligns*/) const override {
    static auto extend = [](const std::string& s, const size_t width) {
      std::string rval;
      size_t lens = len(s);
      for (size_t _ = 0; _ < width / lens; _++) { rval += s; }
      rval += substr(s, 0, width % lens);
      return rval;
    };

    out << col_sepr_.left;
    for (size_t i = 0; i < widths.size(); i++) {
      if (i > 0) { out << col_sepr_.mid; }
      size_t width = (i < spec_widths.size() and spec_widths[i] > 0)
                         ? spec_widths[i]
                         : widths[i];
      out << extend(filler_, width);
    }
    out << col_sepr_.right << std::endl;
  }
};

struct RowSeparators {
  using Separator = RowSeparatorEmpty;
  /* Vars: Row separator shared pointers

     top        - Separator at the top (border above whole table)
     header_mid - Separator below header
     mid        - Separator in between non-header rows
     bottom     - Separator below table (border below whole table)
  */
  std::shared_ptr<RowSeparator> top = std::make_shared<Separator>();
  std::shared_ptr<RowSeparator> header_mid = std::make_shared<Separator>();
  std::shared_ptr<RowSeparator> mid = std::make_shared<Separator>();
  std::shared_ptr<RowSeparator> bottom = std::make_shared<Separator>();
};

struct Layout {
  ColSeparators col_sepr;
  RowSeparators row_sepr;
};

class Table {
 public:
  using Grid = std::vector<Row>;

 private:
  Grid data_;
  Row cur_row_;

  Widths spec_widths_; 
  Aligns spec_aligns_; 
  LineSplitter split_ = Naive; 
  Layout layout_; 
  Widths widths_;
  // bool printed_any_row_ = false; //TODO: to be used in online mode

  std::stringstream ss_;

  // Helpers



  static void aligned_print_(std::ostream& out,
                             const std::string& s,
                             size_t width,
                             Align align);
  static std::string print_(std::ostream& out,
                            const std::string& s,
                            size_t width,
                            Align align,
                            LineSplitter ls);
  Row print_row_line_(std::ostream& out, const Row& row) const;

  void print_row_(std::ostream& out, const Row& row) const;

 public:
  Table& widths(Widths widths_) {
    spec_widths_ = std::move(widths_);
    return *this;
  }
  Table& aligns(Aligns aligns_) {
    spec_aligns_ = std::move(aligns_);
    return *this;
  }
  Table& multiline(LineSplitter mline) {
    split_ = std::move(mline);
    return *this;
  }
  Table& layout(Layout layout) {
    layout_ = std::move(layout);
    return *this;
  }
  Table& precision(const int n) {
    ss_ << std::setprecision(n);
    return *this;
  }
  Table& fixed() {
    ss_ << std::fixed;
    return *this;
  }

  template <typename T>
  Table& operator<<(const T& x);

  void print(std::ostream& out = std::cout) const;
};

template <typename T>
Table& Table::operator<<(const T& x) {
  // insert the value into the table as a string
  ss_ << x;
  ss_.str(normalize_newlines(ss_.str()));
  cur_row_.push_back(ss_.str());

  widths_.resize(std::max(widths_.size(), cur_row_.size()), 0);
  size_t& width = widths_[cur_row_.size() - 1];
  for (std::string s; std::getline(ss_, s); width = std::max(width, len(s))) {}

  ss_.str("");
  ss_.clear();

  return *this;
}

template <>
inline Table& Table::operator<<(const Endr&) {
  data_.push_back(std::move(cur_row_));
  return *this;
}

template <>
inline Table& Table::operator<<(const Cell& c) {
  return *this << normalize_newlines(c.str());
}

inline void Table::aligned_print_(std::ostream& out,
                                  const std::string& s,
                                  size_t width,
                                  Align align) {
  size_t lens = len(s);
  assert(lens <= width and
         s.find('\n') == std::string::npos); // paranoid ¯\_(ツ)_/¯

  if (align == Left) {
    out << s << std::string(width - lens, ' ');
  } else if (align == Center) {
    out << std::string((width - lens) / 2, ' ') << s
        << std::string((width - lens + 1) / 2, ' ');
  } else if (align == Right) {
    out << std::string(width - lens, ' ') << s;
  }
}

inline std::string Table::print_(std::ostream& out,
                                 const std::string& s,
                                 size_t width,
                                 Align align,
                                 LineSplitter ls) {
  std::string head = s;
  std::string tail = "";

  // split by '\n'
  size_t pos = s.find('\n');
  if (pos != std::string::npos) {
    head = s.substr(0, pos);
    tail = s.substr(pos + 1);
  }

  // split by width
  if (len(head) > width) {
    head = substr(s, 0, width);
    tail = substr(s, width);
    if (ls == Space) {
      // split by space
      pos = head.rfind(' ');
      if (pos != std::string::npos) {
        head = s.substr(0, pos);
        tail = s.substr(pos + 1);
      }
    }
  }

  aligned_print_(out, head, width, align);
  return (ls == SingleLine) ? "" : tail;
}

inline Row Table::print_row_line_(std::ostream& out, const Row& row) const {
  Row rval;
  out << layout_.col_sepr.left;
  for (size_t i = 0; i < row.size(); i++) {
    if (i > 0) { out << layout_.col_sepr.mid; }
    size_t width = (i < spec_widths_.size() and spec_widths_[i] > 0)
                       ? spec_widths_[i]
                       : widths_[i];
    Align align = (i < spec_aligns_.size()) ? spec_aligns_[i] : Left;
    rval.push_back(print_(out, row[i], width, align, split_));
  }
  out << layout_.col_sepr.right << std::endl;
  return rval;
}

inline void Table::print_row_(std::ostream& out, const Row& row) const {
  static auto empty = [](const Row& row) {
    return std::all_of(
        row.begin(), row.end(), std::mem_fn(&std::string::empty));
  };

  Row rval = row;
  while (not empty(rval = print_row_line_(out, rval))) {}
}

inline void Table::print(std::ostream& out) const {
  auto& row_sepr = layout_.row_sepr;
  row_sepr.top->print(out, spec_widths_, widths_, spec_aligns_);
  for (size_t i = 0; i < data_.size(); i++) {
    if (i == 1) {
      row_sepr.header_mid->print(out, spec_widths_, widths_, spec_aligns_);
    } else if (i > 1) {
      row_sepr.mid->print(out, spec_widths_, widths_, spec_aligns_);
    }
    print_row_(out, data_[i]);
  }
  row_sepr.bottom->print(out, spec_widths_, widths_, spec_aligns_);
}

inline std::ostream& operator<<(std::ostream& os, const Table& t) {
  t.print(os);
  return os;
}

// Predefined Layouts

inline Layout simple_border(std::string left,
                            std::string center,
                            std::string right,
                            std::string top,
                            std::string header_mid,
                            std::string mid,
                            std::string bottom) {
  ColSeparators cs{std::move(left), std::move(center), std::move(right)};
  RowSeparators rs{
      std::make_shared<RowSeparatorColwise>(cs, std::move(top)),
      std::make_shared<RowSeparatorColwise>(cs, std::move(header_mid)),
      std::make_shared<RowSeparatorColwise>(cs, std::move(mid)),
      std::make_shared<RowSeparatorColwise>(cs, std::move(bottom))};
  return {std::move(cs), std::move(rs)};
}

inline Layout simple_border(std::string left,
                            std::string center,
                            std::string right,
                            std::string header_mid) {
  ColSeparators cs{std::move(left), std::move(center), std::move(right)};
  RowSeparators rs{
      std::make_shared<RowSeparatorEmpty>(),
      std::make_shared<RowSeparatorColwise>(cs, std::move(header_mid)),
      std::make_shared<RowSeparatorEmpty>(),
      std::make_shared<RowSeparatorEmpty>()};
  return {std::move(cs), std::move(rs)};
}

inline Layout
simple_border(std::string left, std::string center, std::string right) {
  ColSeparators cs{std::move(left), std::move(center), std::move(right)};
  RowSeparators rs{std::make_shared<RowSeparatorEmpty>(),
                   std::make_shared<RowSeparatorEmpty>(),
                   std::make_shared<RowSeparatorEmpty>(),
                   std::make_shared<RowSeparatorEmpty>()};
  return {std::move(cs), std::move(rs)};
}

inline Layout markdown() {
  return simple_border("| ", " | ", " |", "-");
}

inline Layout indented_list() {
  return simple_border("  ", "   ", "");
}

class LatexHeader : public RowSeparator {
 public:
  void print(std::ostream& out,
             const Widths& /*spec_widths*/,
             const Widths& /*widths*/,
             const Aligns& aligns) const override {
    out << R"(\begin{tabular}{)";
    for (auto& a : aligns) { out << (char)a; }
    out << "}" << std::endl << R"(\hline)" << std::endl;
  }
};

inline Layout latex() {
  ColSeparators cs{"", " & ", " \\\\"};
  RowSeparators rs{
      std::make_shared<LatexHeader>(),
      std::make_shared<RowSeparatorFlat>("\\hline"),
      std::make_shared<RowSeparatorEmpty>(),
      std::make_shared<RowSeparatorFlat>("\\hline\n\\end{tabular}")};
  return {std::move(cs), std::move(rs)};
}

inline Layout extra_space() {
  return simple_border("  ", "  ", "  ", " ", " ", " ", " ");
}

inline Layout ascii_box() {
  ColSeparators sep{"+", "-", "+"};
  RowSeparators rs{std::make_shared<RowSeparatorColwise>(sep, "-"),
                   std::make_shared<RowSeparatorColwise>(sep, "-"),
                   std::make_shared<RowSeparatorColwise>(sep, "-"),
                   std::make_shared<RowSeparatorColwise>(std::move(sep), "-")};

  return {ColSeparators{"|", "|", "|"}, rs};
}

inline Layout unicode_box_light() {
  ColSeparators top{"┌", "┬", "┐"};
  ColSeparators mid{"├", "┼", "┤"};
  ColSeparators bot{"└", "┴", "┘"};
  RowSeparators rs{std::make_shared<RowSeparatorColwise>(std::move(top), "─"),
                   std::make_shared<RowSeparatorColwise>(mid, "─"),
                   std::make_shared<RowSeparatorColwise>(std::move(mid), "─"),
                   std::make_shared<RowSeparatorColwise>(std::move(bot), "─")};

  return {ColSeparators{"│", "│", "│"}, rs};
}

} // namespace tblr

#endif
```


-------------------------------

Updated on 30 December 2020 at 13:42:56 EST
