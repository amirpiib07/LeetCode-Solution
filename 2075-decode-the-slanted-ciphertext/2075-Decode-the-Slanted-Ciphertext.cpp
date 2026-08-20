class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        int n = encodedText.length();
        int cols = n / rows;

        StringBuilder sb = new StringBuilder();

        for (int j = 0; j < cols; j++) {
            int i = 0, k = j;

            while (i < rows && k < cols) {
                int index = i * cols + k;
                sb.append(encodedText.charAt(index));
                i++;
                k++;
            }
        }

        // Remove trailing spaces
        int end = sb.length() - 1;
        while (end >= 0 && sb.charAt(end) == ' ') end--;

        return sb.substring(0, end + 1);
    }
}