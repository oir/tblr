---

# tblr::Table




 [More...](#detailed-description)


`#include <tblr.h>`







## Public Types

|                | Name           |
| -------------- | -------------- |
| using std::vector< Row > | **[Grid](api/Classes/classtblr_1_1_table.md#using-grid)**  |






## Public Functions

|                | Name           |
| -------------- | -------------- |
| [Table](api/Classes/classtblr_1_1_table.md) & | **[widths](api/Classes/classtblr_1_1_table.md#function-widths)**(Widths widths_)  |
| [Table](api/Classes/classtblr_1_1_table.md) & | **[aligns](api/Classes/classtblr_1_1_table.md#function-aligns)**(Aligns aligns_)  |
| [Table](api/Classes/classtblr_1_1_table.md) & | **[multiline](api/Classes/classtblr_1_1_table.md#function-multiline)**(LineSplitter mline)  |
| [Table](api/Classes/classtblr_1_1_table.md) & | **[layout](api/Classes/classtblr_1_1_table.md#function-layout)**([Layout](api/Classes/structtblr_1_1_layout.md) layout)  |
| [Table](api/Classes/classtblr_1_1_table.md) & | **[precision](api/Classes/classtblr_1_1_table.md#function-precision)**(const int n)  |
| [Table](api/Classes/classtblr_1_1_table.md) & | **[fixed](api/Classes/classtblr_1_1_table.md#function-fixed)**()  |
| template \<typename T \></br>[Table](api/Classes/classtblr_1_1_table.md) & | **[operator<<](api/Classes/classtblr_1_1_table.md#function-operator<<)**(const T & x)  |
| void | **[print](api/Classes/classtblr_1_1_table.md#function-print)**(std::ostream & out =std::cout) const  |
| [Table](api/Classes/classtblr_1_1_table.md) & | **[operator<<](api/Classes/classtblr_1_1_table.md#function-operator<<)**(const [Endr](api/Classes/classtblr_1_1_endr.md) & )  |
| [Table](api/Classes/classtblr_1_1_table.md) & | **[operator<<](api/Classes/classtblr_1_1_table.md#function-operator<<)**(const [Cell](api/Classes/classtblr_1_1_cell.md) & c)  |








## Detailed Description

```cpp
class tblr::Table;
```



























Main class that defines a table with its layout and content. 



## Public Types Documentation

### using Grid

```cpp
using tblr::Table::Grid =  std::vector<Row>;
```



























A collection of rows of a table, which contain the text content. See Row. 








## Public Functions Documentation

### function widths

```cpp
inline Table & widths(
    Widths widths_
)
```



























Set widths of each column. Zero means auto. If there are more columns than widths, underspecified columns default to zero. 


### function aligns

```cpp
inline Table & aligns(
    Aligns aligns_
)
```



























Set alignments of each column. If there are more columns than alignments, underspecified columns default to Left. 


### function multiline

```cpp
inline Table & multiline(
    LineSplitter mline
)
```



























Set multilineness (line splitter) of table. 


### function layout

```cpp
inline Table & layout(
    Layout layout
)
```



























Set layout of table. 


### function precision

```cpp
inline Table & precision(
    const int n
)
```



























Set floating point precision. 


### function fixed

```cpp
inline Table & fixed()
```



























Set fixed notation for printing floats (as opposed to default). 


### function operator<<

```cpp
template <typename T >
Table & operator<<(
    const T & x
)
```



























Stream operator to pipe things _into_ the table. General (unspecialized) version assumes input is streamable to a stream and puts it into the next cell by converting it to string. 


### function print

```cpp
inline void print(
    std::ostream & out =std::cout
) const
```



























Print the table. This is the final method to call after table contents are populated and ready to be displayed / output. 


### function operator<<

```cpp
inline Table & operator<<(
    const Endr & 
)
```



























Specialization of the stream operator for [Endr](api/Classes/classtblr_1_1_endr.md) type to end a row.

Example:



```cpp
t << "hello" << "world" << tblr::endr;
```

_Filename: .cpp_


### function operator<<

```cpp
inline Table & operator<<(
    const Cell & c
)
```



























Specialization of the stream operator for <Cells>. Puts the cell contents into the next cell. 








-------------------------------

Updated on 30 December 2020 at 13:42:56 EST