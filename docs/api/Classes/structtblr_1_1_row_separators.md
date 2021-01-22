---

# tblr::RowSeparators




 [More...](#detailed-description)


`#include <tblr.h>`







## Public Types

|                | Name           |
| -------------- | -------------- |
| using [RowSeparatorEmpty](api/Classes/classtblr_1_1_row_separator_empty.md) | **[Separator](api/Classes/structtblr_1_1_row_separators.md#using-separator)**  |








## Public Attributes

|                | Name           |
| -------------- | -------------- |
| std::shared_ptr< [RowSeparator](api/Classes/classtblr_1_1_row_separator.md) > | **[top](api/Classes/structtblr_1_1_row_separators.md#variable-top)**  |
| std::shared_ptr< [RowSeparator](api/Classes/classtblr_1_1_row_separator.md) > | **[header_mid](api/Classes/structtblr_1_1_row_separators.md#variable-header_mid)**  |
| std::shared_ptr< [RowSeparator](api/Classes/classtblr_1_1_row_separator.md) > | **[mid](api/Classes/structtblr_1_1_row_separators.md#variable-mid)**  |
| std::shared_ptr< [RowSeparator](api/Classes/classtblr_1_1_row_separator.md) > | **[bottom](api/Classes/structtblr_1_1_row_separators.md#variable-bottom)**  |






## Detailed Description

```cpp
struct tblr::RowSeparators;
```



























Collection of row separators that belong to a single table. 



## Public Types Documentation

### using Separator

```cpp
using tblr::RowSeparators::Separator =  RowSeparatorEmpty;
```





































## Public Attributes Documentation

### variable top

```cpp
std::shared_ptr< RowSeparator > top = std::make_shared<[Separator](api/Classes/classtblr_1_1_row_separator_empty.md)>();
```



























Separator at the top (border above whole table) 


### variable header_mid

```cpp
std::shared_ptr< RowSeparator > header_mid = std::make_shared<[Separator](api/Classes/classtblr_1_1_row_separator_empty.md)>();
```





























### variable mid

```cpp
std::shared_ptr< RowSeparator > mid = std::make_shared<[Separator](api/Classes/classtblr_1_1_row_separator_empty.md)>();
```





























### variable bottom

```cpp
std::shared_ptr< RowSeparator > bottom = std::make_shared<[Separator](api/Classes/classtblr_1_1_row_separator_empty.md)>();
```

































-------------------------------

Updated on 30 December 2020 at 13:42:56 EST