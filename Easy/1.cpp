/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //一年前写的，居然是用C得到的AC，摸摸自己╰(￣ω￣ｏ)
int* twoSum(int* nums, int numsSize, int target) {
    int a,b;
    for(int i = 0; i < numsSize - 1; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                a = i;
                b = j;
            }
        }
    }

    int *res = (int*)malloc(2 * sizeof(int));

    res[0] = a;
    res[1] = b;

    return res;
}
