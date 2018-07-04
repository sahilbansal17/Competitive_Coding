package Gssoc;

public class CrossWord {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		char[][] box = {
				{ '+', '-', '+', '+', '+', '+', '+', '+', '+', '+' },
				{ '+', '-', '+', '+', '+', '+', '+', '+', '+', '+' },
				{ '+', '-', '+', '+', '+', '+', '+', '+', '+', '+' },
				{ '+', '-', '-', '-', '-', '-', '+', '+', '+', '+' },
				{ '+', '-', '+', '+', '+', '-', '+', '+', '+', '+' },
				{ '+', '-', '+', '+', '+', '-', '+', '+', '+', '+' },
				{ '+', '+', '+', '+', '+', '-', '+', '+', '+', '+' },
				{ '+', '+', '-', '-', '-', '-', '-', '-', '+', '+' },
				{ '+', '+', '+', '+', '+', '-', '+', '+', '+', '+' },
				{ '+', '+', '+', '+', '+', '-', '+', '+', '+', '+' } 
			};
		String[] words = { "DELHI", "ICELAND", "ANKARA", "LONDON" };
		crossword(box, words, 0);
	}

	private static void crossword(char[][] box, String[] words, int idex) {

		if (idex == words.length) {
			for (int r = 0; r < box.length; r++) {
				for (int c = 0; c < box[0].length; c++) {
					System.out.print(box[r][c]);
				}
				System.out.println();
			}
			return;
		}

		String word = words[idex];
		for (int r = 0; r < box.length; r++) {
			for (int c = 0; c < box[0].length; c++) {
				if (box[r][c] == '-' || box[r][c] == word.charAt(0)) {
					// vertically
					if (canPlaceTheWordVertically(box, word, r, c) == true) {
						boolean[] reset = placeTheWordVertically(box, word, r, c);
						crossword(box, words, idex + 1);
						unPlaceTheWordVertically(box, reset, r, c);
					}

					// horizontally
					if (canPlaceTheWordHorizontally(box, word, r, c) == true) {
						boolean[] reset = placeTheWordHorizontally(box, word, r, c);
						crossword(box, words, idex + 1);
						unPlaceTheWordHorizontally(box, reset, r, c);
					}
				}
			}
		}
	}

	public static boolean canPlaceTheWordVertically(char[][] box, String word, int r, int c) {

		for (int i = 0; i < word.length(); i++) {
			if (r + i >= box.length) {
				return false;
			} else if (box[r + i][c] != '-' && box[r + i][c] != word.charAt(i)) {
				return false;
			}
		}
		return true;
	}

	public static boolean canPlaceTheWordHorizontally(char[][] box, String word, int r, int c) {
		for (int i = 0; i < word.length(); i++) {
			if (c + i >= box[0].length) {
				return false;
			} else if (box[r][c + i] != '-' && box[r][c + i] != word.charAt(i)) {
				return false;
			}
		}
		return true;
	}

	public static boolean[] placeTheWordVertically(char[][] box, String word, int r, int c) {
		boolean[] reset = new boolean[word.length()];
		for (int i = 0; i < word.length(); i++) {
			if (box[r + i][c] == '-') {
				reset[i] = true;
				box[r + i][c] = word.charAt(i);
			}
		}
		return reset;
	}

	public static boolean[] placeTheWordHorizontally(char[][] box, String word, int r, int c) {
		boolean[] reset = new boolean[word.length()];
		for (int i = 0; i < word.length(); i++) {
			if (box[r][c + i] == '-') {
				reset[i] = true;
				box[r][c + i] = word.charAt(i);
			}
		}
		return reset;
	}

	public static void unPlaceTheWordVertically(char[][] box, boolean[] reset, int r, int c) {
		for (int i = 0; i < reset.length; i++) {
			if (reset[i] == true) {
				box[r + i][c] = '-';
			}
		}
	}

	public static void unPlaceTheWordHorizontally(char[][] box, boolean[] reset, int r, int c) {
		for (int i = 0; i < reset.length; i++) {
			if (reset[i] == true) {
				box[r][c + i] = '-';
			}
		}

	}

}
