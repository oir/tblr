---

# tblr::Cell




 [More...](#detailed-description)


`#include <tblr.h>`













## Public Functions

|                | Name           |
| -------------- | -------------- |
| std::string | **[str](api/Classes/classtblr_1_1_cell.md#function-str)**() const  |




## Friends

|                | Name           |
| -------------- | -------------- |
| [Cell](api/Classes/classtblr_1_1_cell.md) & | **[operator<<](api/Classes/classtblr_1_1_cell.md#friend-operator<<)**([Cell](api/Classes/classtblr_1_1_cell.md) & c, const T & x)  |
| [Cell](api/Classes/classtblr_1_1_cell.md) && | **[operator<<](api/Classes/classtblr_1_1_cell.md#friend-operator<<)**([Cell](api/Classes/classtblr_1_1_cell.md) && c, const T & x)  |




## Detailed Description

```cpp
class tblr::Cell;
```



























Helper class to use stream operator (<<) without moving to the next column, piping into the same cell of the table. 









## Public Functions Documentation

### function str

```cpp
inline std::string str() const
```

































## Friends

### friend operator<<

```cpp
friend Cell & operator<<(
    Cell & c,
    const T & x
);
```





























### friend operator<<

```cpp
friend Cell && operator<<(
    Cell && c,
    const T & x
);
```































-------------------------------

Updated on 30 December 2020 at 13:42:56 EST