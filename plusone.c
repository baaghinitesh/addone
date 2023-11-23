int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
 int carry = 1;  // Initialize the carry to 1 for adding 1 to the last digit

    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;  // Update the current digit
        carry = sum / 10;      // Update the carry

        // If there is no carry, no need to continue checking
        if (carry == 0) {
            break;
        }
    }

    // If there is still a carry, we need to add a new digit at the beginning
    if (carry > 0) {
        (*returnSize) = digitsSize + 1;
        int* result = (int*)malloc((*returnSize) * sizeof(int));
        if (result == NULL) {
            return NULL;  // Memory allocation failure
        }

        result[0] = carry;
        for (int i = 1; i < (*returnSize); i++) {
            result[i] = digits[i - 1];
        }

        return result;
    } else {
        (*returnSize) = digitsSize;
        return digits;
    }
}