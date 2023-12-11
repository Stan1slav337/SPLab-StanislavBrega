#include "Book.hpp"
#include "Paragraph.hpp"
#include "ImageProxy.hpp"
#include "AlignCenter.hpp"
#include "AlignRight.hpp"
#include "AlignLeft.hpp"

#include <iomanip>

template<typename T>
double timeElapsed(T start, T end)
{
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

int main() 
{
    Section* cap1 = new Section("Capitolul 1");
    Paragraph* p1 = new Paragraph("Paragraph 1");
    cap1->add(p1);
    Paragraph* p2 = new Paragraph("Paragraph 2");
    cap1->add(p2);
    Paragraph* p3 = new Paragraph("Paragraph 3");
    cap1->add(p3);
    Paragraph* p4 = new Paragraph("Paragraph 4");
    cap1->add(p4);
    std::cout << "Printing without Alignment\n\n";
    cap1->print();
    p1->setAlignStrategy(new AlignCenter());
    p2->setAlignStrategy(new AlignRight());
    p3->setAlignStrategy(new AlignLeft());
    std::cout << "\nPrinting with Alignment\n";
    cap1->print();

	return 0;
}
