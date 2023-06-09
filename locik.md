``` c
arr = [0, 0, 0, 1, 1, 0]

while(!(arr[2] == 1 && arr[3] == 1))
    pos = -1

    for (i=0; arr[i]; ++i)
        if (arr[i] == 1) pos = i

        if(pos < 3) left()
    if(pos > 3) right()
```
