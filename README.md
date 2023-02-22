# DMapProblem


## Compilation

To compile just run `make` in the `DMapProblem` directory.

```bash
make
./DMapProblem
```

Expected (correct) result

```bash
{2}
{1}
{-0.5}
{0.166667}
{-0.0416667}
{0.00833333}
```

The program with optimalization `-O2` returns not correct results 

```bash
{2}
{1}
{-0.5}
{0}
{0}
{0}
```
The problem seems to be localized in `include/capd/autodiff/EvalSub.h` in **ConstMinusVar** in lines 70-116:

Changes that gives correct results:
* switching optimalization to `O0`, `O1`
* replacing lines 75-78 in `include/capd/autodiff/EvalSub.h`:
  
  ```cpp
  if(coeffNo)
    result[coeffNo] = -right[coeffNo];
  else
    *result = *left - *right;
  ```
  
  with
  
  ```cpp
  result[coeffNo] = (coeffNo!=0) ? -right[coeffNo] : *left - *right;
  ```
  
* 

