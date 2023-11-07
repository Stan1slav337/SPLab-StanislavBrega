#include <iostream>
#include <vector>
#include <string>

class Element {
public:
    virtual std::string toString() const = 0;
};

class Author {
private:
    std::string name;

public:
    Author(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }
};

class Chapter {
private:
    std::string title;
    std::vector<class SubChapter> subChapters;

public:
    Chapter(const std::string& title) : title(title) {}

    void addSubChapter(const SubChapter& subChapter) {
        subChapters.push_back(subChapter);
    }

    const std::string& getTitle() const {
        return title;
    }

    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    const std::vector<SubChapter>& getSubChapters() const {
        return subChapters;
    }
};

class SubChapter {
private:
    std::string title;
    std::vector<Element*> elements;

public:
    SubChapter(const std::string& title) : title(title) {}

    void addElement(Element* element) {
        elements.push_back(element);
    }

    const std::string& getTitle() const {
        return title;
    }

    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    void createNewParagraph(const std::string& text) {
        elements.push_back(new Paragraph(text));
    }

    void createNewImage(const std::string& imageURL) {
        elements.push_back(new Image(imageURL));
    }

    void createNewTable(const std::string& title) {
        elements.push_back(new Table(title));
    }

    void print() const {
        std::cout << "SubChapter: " << title << std::endl;
        for (const Element* element : elements) {
            std::cout << element->toString() << std::endl;
        }
    }
};

class Image : public Element {
private:
    std::string imageURL;

public:
    Image(const std::string& imageURL) : imageURL(imageURL) {}

    std::string toString() const override {
        return "Image with name: " + imageURL;
    }
};

class Paragraph : public Element {
private:
    std::string text;

public:
    Paragraph(const std::string& text) : text(text) {}

    std::string toString() const override {
        return text;
    }
};

class Table : public Element {
private:
    std::string title;

public:
    Table(const std::string& title) : title(title) {}

    std::string toString() const override {
        return "Table with name: " + title;
    }
};

class Book {
private:
    std::string title;
    Author author;
    std::vector<Chapter> chapters;

public:
    Book(const std::string& title) : title(title) {}

    void addAuthor(const Author& newAuthor) {
        author = newAuthor;
    }

    void addChapter(const Chapter& chapter) {
        chapters.push_back(chapter);
    }

    const std::vector<Chapter>& getChapters() const {
        return chapters;
    }

    int createChapter(const std::string& chapterTitle) {
        chapters.push_back(Chapter(chapterTitle));
        return chapters.size() - 1;
    }

    Chapter& getChapter(int index) {
        if (index >= 0 && static_cast<size_t>(index) < chapters.size()) {
            return chapters[index];
        }
        throw std::out_of_range("Chapter index out of bounds");
    }
};

int main() {
    Book discoTitanic("Disco Titanic");
    Author author("Radu Pavel Gheo");
    discoTitanic.addAuthor(author);
    int indexChapterOne = discoTitanic.createChapter("Capitolul 1");
    Chapter& chp1 = discoTitanic.getChapter(indexChapterOne);
    int indexSubChapterOneOne = chp1.createSubChapter("Subcapitolul 1.1");
    SubChapter scOneOne = chp1.getSubChapters()[indexSubChapterOneOne];
    scOneOne.createNewParagraph("Paragraph 1");
    scOneOne.createNewParagraph("Paragraph 2");
    scOneOne.createNewParagraph("Paragraph 3");
    scOneOne.createNewImage("Image 1");
    scOneOne.createNewParagraph("Paragraph 4");
    scOneOne.createNewTable("Table 1");
    scOneOne.createNewParagraph("Paragraph 5");
    scOneOne.print();
}
