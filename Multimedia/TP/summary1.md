
### Indexing and Slicing

For a 2D NumPy array, these methods allow for flexible data selection and manipulation:

1. **Row and Column Selection**:
   - `a[1, :]` – Selects all columns of the 2nd row.
   - `a[:, 1:2]` – Selects all rows of the 2nd column while keeping a 2D shape.

2. **Using Negative Indices**:
   - `a[:, -1]` – Selects the last column of all rows.
   - `a[:, -1:]` – Selects the last column in 2D shape.
   - `a[:, -2]` – Selects the second-to-last column.
   - `a[:, -2:-1]` – Selects the second-to-last column in 2D shape.

3. **Subarray Selection**:
   - `a[:, -2:]` – Selects the last two columns for all rows.
   - `a[0:3, 0:1]` – Selects the first column of rows 0 to 2.
   - `a[0:1, 2:3]` – Selects a specific element (row 0, column 2) in 2D shape.

### Masking and Conditional Selection

With NumPy’s `masked_array`, certain elements can be "masked" based on conditions:

- **Example**:
   ```python
   from numpy import ma
   arr = array([1, 2, 3, 4, 5, 6, 7, 8, 9])
   ma_arr = ma.masked_array(arr, mask=arr < 4)  # Masks elements less than 4
   ```

### Summary of Example Code
```python
from numpy import array, ma

# Define a 2D array
a = array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

# Slicing Examples
print(a[1, :])       # All columns of the 2nd row
print(a[:, 1:2])     # All rows of the 2nd column in 2D shape
print(a[:, -1])      # Last column for all rows
print(a[0:1, 2:3])   # Element at row 0, column 2 in 2D shape

# Masking Example
arr = array([1, 2, 3, 4, 5, 6, 7, 8, 9])
ma_arr = ma.masked_array(arr, mask=arr < 4)  # Masks elements less than 4
print(ma_arr)  # Displays masked elements based on the condition
```

