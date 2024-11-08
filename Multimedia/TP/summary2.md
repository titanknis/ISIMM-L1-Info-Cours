
### Selection Techniques for Masking and Filtering Elements in NumPy Arrays

### 1. **Comparison Operations**
   - **Less than**: `arr < 5` – Selects elements less than 5.
   - **Greater than**: `arr > 5` – Selects elements greater than 5.
   - **Equal to**: `arr == 5` – Selects elements equal to 5.
   - **Not equal to**: `arr != 5` – Selects elements not equal to 5.

### 2. **Logical Operations**
   - **AND**: `(arr > 2) & (arr < 7)` – Selects elements between 2 and 7.
   - **OR**: `(arr < 3) | (arr > 8)` – Selects elements less than 3 or greater than 8.
   - **NOT**: `~(arr < 5)` – Selects elements not less than 5.

### 3. **Boolean Indexing**
   - **Selection**: `arr[arr < 5]` – Retrieves elements less than 5.
   - **Modification**: `arr[arr > 5] = 0` – Sets elements greater than 5 to 0.
