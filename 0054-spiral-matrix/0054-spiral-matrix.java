class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();          // Stores the Output

        int top = 0;                                    // Top row
        int rightColumn = matrix[0].length - 1;     // Right Column
        int bottom = matrix.length - 1;             // Bottom row
        int leftColumn = 0;                         // Left Column

        while (top <= bottom && rightColumn >= leftColumn) {
            // Print Top
            for (int i = leftColumn; i <= rightColumn ; i++) {
                ans.add(matrix[top][i]);
            }
            top++;

            // Print Right Column
            for (int i = top; i <= bottom; i++) {
                ans.add(matrix[i][rightColumn]);
            }
            rightColumn--;

            // Print bottom
            if(top <= bottom){
                for (int i = rightColumn; i >= leftColumn; i--) {
                    ans.add(matrix[bottom][i]);
                }
                bottom--;
            }

            // Print Left Column
            if(leftColumn <= rightColumn){
                for (int i = bottom; i >= top; i--) {
                    ans.add(matrix[i][leftColumn]);
                }
                leftColumn++;
            }
            
        }
        return ans;
    }
}