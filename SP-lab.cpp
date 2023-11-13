#include "Book.hpp"

int main() {
	Book discoTitanic = Book("Disco Titanic");
	Author author = Author("Radu Pavel Gheo");
	discoTitanic.addAuthor(author);
	int indexChapterOne = discoTitanic.createChapter("Capitolul 1");
	Chapter chp1 = discoTitanic.getChapter(indexChapterOne);
	int indexSubChapterOneOne = chp1.createSubChapter("Subcapitolul 1.1");
	SubChapter scOneOne = chp1.getSubChapter(indexSubChapterOneOne);
	scOneOne.createNewParagraph("Paragraph 1");
	scOneOne.createNewParagraph("Paragraph 2");
	scOneOne.createNewParagraph("Paragraph 3");
	scOneOne.createNewImage("Image 1");
	scOneOne.createNewParagraph("Paragraph 4");
	scOneOne.createNewTable("Table 1");
	scOneOne.createNewParagraph("Paragraph 5");
	scOneOne.print();
}
