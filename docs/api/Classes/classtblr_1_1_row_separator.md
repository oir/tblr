---

# tblr::RowSeparator




 [More...](#detailed-description)


`#include <tblr.h>`



Inherited by [tblr::LatexHeader](api/Classes/classtblr_1_1_latex_header.md), [tblr::RowSeparatorColwise](api/Classes/classtblr_1_1_row_separator_colwise.md), [tblr::RowSeparatorEmpty](api/Classes/classtblr_1_1_row_separator_empty.md), [tblr::RowSeparatorFlat](api/Classes/classtblr_1_1_row_separator_flat.md)










## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[print](api/Classes/classtblr_1_1_row_separator.md#function-print)**(std::ostream & out, const Widths & spec_widths, const Widths & widths, const Aligns & aligns) const =0  |
| virtual  | **[~RowSeparator](api/Classes/classtblr_1_1_row_separator.md#function-~rowseparator)**()  |








## Detailed Description

```cpp
class tblr::RowSeparator;
```



























Base class for row delimiters (horizontal lines between rows). 









## Public Functions Documentation

### function print

```cpp
virtual void print(
    std::ostream & out,
    const Widths & spec_widths,
    const Widths & widths,
    const Aligns & aligns
) const =0
```


**Parameters**: 

  * **out** Output stream to print 
  * **spec_widths** User specified widths of each column 
  * **widths** Computed widths of each column (from content text) 
  * **aligns** User specified alignments of each column 

























**Reimplemented by**: [tblr::RowSeparatorEmpty::print](api/Classes/classtblr_1_1_row_separator_empty.md#function-print), [tblr::RowSeparatorFlat::print](api/Classes/classtblr_1_1_row_separator_flat.md#function-print), [tblr::LatexHeader::print](api/Classes/classtblr_1_1_latex_header.md#function-print), [tblr::RowSeparatorColwise::print](api/Classes/classtblr_1_1_row_separator_colwise.md#function-print)


Print row separator to stream. 


### function ~RowSeparator

```cpp
inline virtual ~RowSeparator()
```



































-------------------------------

Updated on 30 December 2020 at 13:42:56 EST