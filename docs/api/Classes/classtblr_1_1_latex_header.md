---

# tblr::LatexHeader








Inherits from [tblr::RowSeparator](api/Classes/classtblr_1_1_row_separator.md)











## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[print](api/Classes/classtblr_1_1_latex_header.md#function-print)**(std::ostream & out, const Widths & spec_widths, const Widths & widths, const Aligns & aligns) const override  |






## Additional inherited members










**Public Functions inherited from [tblr::RowSeparator](api/Classes/classtblr_1_1_row_separator.md)**

|                | Name           |
| -------------- | -------------- |
| virtual  | **[~RowSeparator](api/Classes/classtblr_1_1_row_separator.md#function-~rowseparator)**()  |















## Public Functions Documentation

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