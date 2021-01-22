---

# tblr::RowSeparatorFlat




 [More...](#detailed-description)


`#include <tblr.h>`


Inherits from [tblr::RowSeparator](api/Classes/classtblr_1_1_row_separator.md)











## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[RowSeparatorFlat](api/Classes/classtblr_1_1_row_separator_flat.md#function-rowseparatorflat)**(std::string sepr ="")  |
| virtual void | **[print](api/Classes/classtblr_1_1_row_separator_flat.md#function-print)**(std::ostream & out, const Widths & spec_widths, const Widths & widths, const Aligns & aligns) const override  |






## Additional inherited members










**Public Functions inherited from [tblr::RowSeparator](api/Classes/classtblr_1_1_row_separator.md)**

|                | Name           |
| -------------- | -------------- |
| virtual  | **[~RowSeparator](api/Classes/classtblr_1_1_row_separator.md#function-~rowseparator)**()  |







## Detailed Description

```cpp
class tblr::RowSeparatorFlat;
```



























A row separator that does not align to columns (e.g. Latex's \hline). 









## Public Functions Documentation

### function RowSeparatorFlat

```cpp
inline RowSeparatorFlat(
    std::string sepr =""
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