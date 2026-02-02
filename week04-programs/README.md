# Week 04 - Functions and Decomposition

## Learning Goals 

- Break problems into pieces
- Functions have responsibility

### Mental Model 

A function is a contract: input → output.

#### Prompts 

- What problem does this function solve? 

    I don't think about this often enough, I often just write code and then update it later with refactored code. I think
    as with most of my programming, I need to think more before just writing code and hoping that it works. I think that
    it is important to realize that I control the modularity of the code and should think about cleaning up the code as I write it
    and not later. 
- What should this function NOT do? 

    This function should not do anything unrelated, or outside its scope. It is important when naming to think, "Does
    this name of the function require an 'and'". If it does, then it is probably doing too much. 
- What inputs does this function need?

    It depends on what you want to create with the function. Inputs are values from outside the function that need to be
    used to create the output.

```C 
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int nums1_current_largest = m - 1; 
    int nums2_new_largest = n - 1; 

    for (int i = nums1Size - 1; i >= 0; i--) {
        if (nums2_new_largest < 0) {
            break;
        } 

        if (nums1_current_largest < 0) {
            nums1[i] = nums2[nums2_new_largest--];
            continue;
        }
        int largest_new = nums2[nums2_new_largest];
        int largest_current = nums1[nums1_current_largest];
        if (largest_new >= largest_current) {
            nums1[i] = largest_new;
            nums2_new_largest--;
        } else {
            nums1[i] = largest_current;
            nums1_current_largest--;
        }
    }
}
```
