# BoolArray
Class for storage of boolean values.

```
BoolArray<14> a;

a.Set(1, true);
a.Set(12, true);

std::cout << a.Get(1) << std::endl;
std::cout << a.Get(11) << std::endl;

// Throws out "index out of range" error.
a.Set(19, true);
std::cout << a.Get(19) << std::endl;
```
