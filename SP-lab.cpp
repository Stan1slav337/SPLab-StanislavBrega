#include "Visitor.hpp"
#include "RenderContentVisitor.hpp"
#include "TableOfContentUpdate.hpp"
#include "AlignCenter.hpp"
#include "AlignLeft.hpp"
#include "AlignRight.hpp"

#include <iomanip>

template<typename T>
double timeElapsed(T start, T end)
{
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

int main()
{
    Book* b = new Book("The book");
    Section* cap1 = new Section("Chapter 1");
    Section* cap11 = new Section("Subchapter 1.1");
    Section* cap2 = new Section("Chapter 2");
    cap1->add(new Paragraph("Paragraph 1"));
    cap1->add(new Paragraph("Paragraph 2"));
    cap1->add(new Paragraph("Paragraph 3"));

    cap11->add(new ImageProxy("ImageOne"));
    cap11->add(new Image("ImageTwo"));

    cap2->add(new Paragraph("Paragraph 4"));
    Paragraph* p4 = new Paragraph("Paragraph 4");
    cap2->add(p4);
    cap1->add(cap11);
    cap1->add(new Paragraph("Some text"));
    cap1->add(new Table("Table 1"));

    b->addContent(cap1);
    b->addContent(cap2);

    //RenderContentVisitor* render = new RenderContentVisitor();
    //render->visitBook(*b);

    TableOfContentUpdate* tocUpdate = new TableOfContentUpdate();
    b->accept(*tocUpdate);
    tocUpdate->showTable();

    return 0;
}
