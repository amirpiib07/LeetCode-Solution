class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        int n = encodedText.length();
        int cols = n / rows;

        char[][] mat = new char[rows][cols];
        int idx = 0;

        // Fill matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText.charAt(idx++);
            }
        }

        StringBuilder sb = new StringBuilder();

        // Traverse diagonals
        for (int j = 0; j < cols; j++) {
            int i = 0, k = j;
            while (i < rows && k < cols) {
                sb.append(mat[i][k]);
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