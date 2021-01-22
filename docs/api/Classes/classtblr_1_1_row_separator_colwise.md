---

# tblr::RowSeparatorColwise




 [More...](#detailed-description)


`#include <tblr.h>`


Inherits from [tblr::RowSeparator](api/Classes/classtblr_1_1_row_separator.md)











## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[RowSeparatorColwise](api/Classes/classtblr_1_1_row_separator_colwise.md#function-rowseparatorcolwise)**([ColSeparators](api/Classes/structtblr_1_1_col_separators.md) csep ={}, std::string fill =" ")  |
| virtual void | **[print](api/Classes/classtblr_1_1_row_separator_colwise.md#function-print)**(std::ostream & out, const Widths & spec_widths, const Widths & widths, const Aligns & aligns) const override  |






## Additional inherited members










**Public Functions inherited from [tblr::RowSeparator](api/Classes/classtblr_1_1_row_separator.md)**

|                | Name           |
| -------------- | -------------- |
| virtual  | **[~RowSeparator](api/Classes/classtblr_1_1_row_separator.md#function-~rowseparator)**()  |







## Detailed Description

```cpp
class tblr::RowSeparatorColwise;
```



























A row separator that has column separators within that aligns to each cell/column (e.g. Markdown) 









## Public Functions Documentation

### function RowSeparatorColwise

```cpp
inline RowSeparatorColwise(
    ColSeparators csep ={},
    std::string fill =" "
)
```





























### function print

```cpp
inline virtual void print(
    std::ostream & out,
    const Widths & spec_widths,
    const Widths & widths,
    const Aligns & aligns
) const override
```


**Parameters**: 

  * **out** Output stream to print 
  * **spec_widths** User specified widths of each column 
  * **widths** Computed widths of each column (from content text) 
  * **aligns** User specified alignments of each column 

























**Reimplements**: [tblr::RowSeparator::print](api/Classes/classtblr_1_1_row_separator.md#function-print)


Print row separator to stream. 








-------------------------------

Updated on 30 December 2020 at 13:42:56 EST