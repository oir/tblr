---

# tblr










## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[tblr::Cell](api/Classes/classtblr_1_1_cell.md)**  |
| struct | **[tblr::ColSeparators](api/Classes/structtblr_1_1_col_separators.md)**  |
| class | **[tblr::Endr](api/Classes/classtblr_1_1_endr.md)**  |
| class | **[tblr::LatexHeader](api/Classes/classtblr_1_1_latex_header.md)**  |
| struct | **[tblr::Layout](api/Classes/structtblr_1_1_layout.md)**  |
| class | **[tblr::RowSeparator](api/Classes/classtblr_1_1_row_separator.md)**  |
| class | **[tblr::RowSeparatorColwise](api/Classes/classtblr_1_1_row_separator_colwise.md)**  |
| class | **[tblr::RowSeparatorEmpty](api/Classes/classtblr_1_1_row_separator_empty.md)**  |
| class | **[tblr::RowSeparatorFlat](api/Classes/classtblr_1_1_row_separator_flat.md)**  |
| struct | **[tblr::RowSeparators](api/Classes/structtblr_1_1_row_separators.md)**  |
| class | **[tblr::Table](api/Classes/classtblr_1_1_table.md)**  |

## Types

|                | Name           |
| -------------- | -------------- |
| enum char | **[Align](api/Namespaces/namespacetblr.md#enum-align)** { Left = 'l', Center = 'c', Right = 'r' } |
| enum | **[LineSplitter](api/Namespaces/namespacetblr.md#enum-linesplitter)** { SingleLine, Naive, Space } |
| using std::vector< std::string > | **[Row](api/Namespaces/namespacetblr.md#using-row)**  |
| using std::vector< size_t > | **[Widths](api/Namespaces/namespacetblr.md#using-widths)**  |
| using std::vector< Align > | **[Aligns](api/Namespaces/namespacetblr.md#using-aligns)**  |



## Functions

|                | Name           |
| -------------- | -------------- |
| bool | **[is_first_byte](api/Namespaces/namespacetblr.md#function-is_first_byte)**(const char & c)  |
| size_t | **[len](api/Namespaces/namespacetblr.md#function-len)**(const std::string & s)  |
| std::string | **[substr](api/Namespaces/namespacetblr.md#function-substr)**(const std::string & s, size_t left =0, size_t size =-1)  |
| std::string | **[normalize_newlines](api/Namespaces/namespacetblr.md#function-normalize_newlines)**(const std::string & s)  |
| std::ostream & | **[operator<<](api/Namespaces/namespacetblr.md#function-operator<<)**(std::ostream & os, const [Table](api/Classes/classtblr_1_1_table.md) & t)  |
| [Layout](api/Classes/structtblr_1_1_layout.md) | **[simple_border](api/Namespaces/namespacetblr.md#function-simple_border)**(std::string left, std::string center, std::string right, std::string top, std::string header_mid, std::string mid, std::string bottom)  |
| [Layout](api/Classes/structtblr_1_1_layout.md) | **[simple_border](api/Namespaces/namespacetblr.md#function-simple_border)**(std::string left, std::string center, std::string right, std::string header_mid)  |
| [Layout](api/Classes/structtblr_1_1_layout.md) | **[simple_border](api/Namespaces/namespacetblr.md#function-simple_border)**(std::string left, std::string center, std::string right)  |
| [Layout](api/Classes/structtblr_1_1_layout.md) | **[markdown](api/Namespaces/namespacetblr.md#function-markdown)**()  |
| [Layout](api/Classes/structtblr_1_1_layout.md) | **[indented_list](api/Namespaces/namespacetblr.md#function-indented_list)**()  |
| [Layout](api/Classes/structtblr_1_1_layout.md) | **[latex](api/Namespaces/namespacetblr.md#function-latex)**()  |
| [Layout](api/Classes/structtblr_1_1_layout.md) | **[extra_space](api/Namespaces/namespacetblr.md#function-extra_space)**()  |
| [Layout](api/Classes/structtblr_1_1_layout.md) | **[ascii_box](api/Namespaces/namespacetblr.md#function-ascii_box)**()  |
| [Layout](api/Classes/structtblr_1_1_layout.md) | **[unicode_box_light](api/Namespaces/namespacetblr.md#function-unicode_box_light)**()  |

## Attributes

|                | Name           |
| -------------- | -------------- |
| const [Endr](api/Classes/classtblr_1_1_endr.md) | **[endr](api/Namespaces/namespacetblr.md#variable-endr)**  |
| const [Endr](api/Classes/classtblr_1_1_endr.md) | **[endl](api/Namespaces/namespacetblr.md#variable-endl)**  |





## Types Documentation

### enum Align


| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| Left | 'l' |   |
| Center | 'c' |   |
| Right | 'r' |   |





























Alignment (justification) of text within a table cell. 


### enum LineSplitter


| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| SingleLine |  |   |
| Naive |  |   |
| Space |  |   |































* SingleLine - Do not split cell text into lines
* Naive - Split cell text into lines exactly by column width
* Space - Split cell text into lines while trying to avoid consecutive non-whitespace chars 


### using Row

```cpp
using tblr::Row = typedef std::vector<std::string>;
```



























Vector of strings that constitute a row of a table. Each element belongs to a cell. 


### using Widths

```cpp
using tblr::Widths = typedef std::vector<size_t>;
```



























Vector of widths for each column of a table. A zero width value means automatic: width is determined by the longest cell in that column. 


### using Aligns

```cpp
using tblr::Aligns = typedef std::vector<Align>;
```



























Vector of alignments per column. See Align. 



## Functions Documentation

### function is_first_byte

```cpp
inline bool is_first_byte(
    const char & c
)
```



























Is first byte of a UTF8 character 


### function len

```cpp
inline size_t len(
    const std::string & s
)
```



























UTF8 length of a string 


### function substr

```cpp
inline std::string substr(
    const std::string & s,
    size_t left =0,
    size_t size =-1
)
```



























UTF8 aware substring 


### function normalize_newlines

```cpp
std::string normalize_newlines(
    const std::string & s
)
```



























Replace all appearances of "\r", "\r\n" with "\n" 


### function operator<<

```cpp
inline std::ostream & operator<<(
    std::ostream & os,
    const Table & t
)
```



























Stream operator to stream a table to an output stream. Alternative to calling <[Table::print](api/Classes/classtblr_1_1_table.md#function-print)> explicitly. 


### function simple_border

```cpp
inline Layout simple_border(
    std::string left,
    std::string center,
    std::string right,
    std::string top,
    std::string header_mid,
    std::string mid,
    std::string bottom
)
```



























Creates a simple layout with specified border elements. Row separators align to columns. 


### function simple_border

```cpp
inline Layout simple_border(
    std::string left,
    std::string center,
    std::string right,
    std::string header_mid
)
```



























Creates a simple layout with specified column separators and only a single row separator between the header and the rest of the table. Separator aligns to columns. 


### function simple_border

```cpp
inline Layout simple_border(
    std::string left,
    std::string center,
    std::string right
)
```



























Creates a simple layout with specified column separators and no row separators. 


### function markdown

```cpp
inline Layout markdown()
```



























Creates layout with markdown table syntax. Resulting table can be copy pasted into markdown. Markdown specific alignment syntax is not yet supported. 


### function indented_list

```cpp
inline Layout indented_list()
```



























Creates a very basic indented list layout with whitespace delimiters. 


### function latex

```cpp
inline Layout latex()
```



























Creates a layout that matches latex tabular syntax. Resulting table can be copy pasted into latex code within a table field. Alignments are also converted to latex alignment syntax as part of the tabular command. 


### function extra_space

```cpp
inline Layout extra_space()
```



























Creates a spacious layout. 


### function ascii_box

```cpp
inline Layout ascii_box()
```



























Creates a box layout with ascii edges and corners 


### function unicode_box_light

```cpp
inline Layout unicode_box_light()
```



























Creates a box layout with light unicode borders 



## Attributes Documentation

### variable endr

```cpp
static const Endr endr;
```





























### variable endl

```cpp
static const Endr endl;
```
































-------------------------------

Updated on 30 December 2020 at 13:42:56 EST