#include "Book.hpp"
#include "Paragraph.hpp"
#include "ImageProxy.hpp"

#include <iomanip>

template<typename T>
double timeElapsed(T start, T end)
{
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

int main() {
    auto startTime = std::chrono::system_clock::now();

    ImageProxy* img1 = new ImageProxy("Pamela Anderson");
    ImageProxy* img2 = new ImageProxy("Kim Kardashian");
    ImageProxy* img3 = new ImageProxy("Kirby Griffin");

    Section* playboyS1 = new Section("Front Cover");
    playboyS1->add(img1);

    Section* playboyS2 = new Section("Summer Girls");
    playboyS2->add(img2);
    playboyS2->add(img3);

    Book* playboy = new Book("Playboy");
    playboy->addContent(playboyS1);
    playboy->addContent(playboyS2);

    auto endTime = std::chrono::system_clock::now();
    std::cout << std::setprecision(3) << "Creation of the content took " << timeElapsed(startTime, endTime) << " seconds" << std::endl;

    startTime = std::chrono::system_clock::now();
    playboyS1->print();
    endTime = std::chrono::system_clock::now();
    std::cout << std::setprecision(3) << "Printing of the section 1 took " << timeElapsed(startTime, endTime) << " seconds" << std::endl;

    startTime = std::chrono::system_clock::now();
    playboyS1->print();
    endTime = std::chrono::system_clock::now();
    std::cout << std::setprecision(3) << "Printing again the section 1 took " << timeElapsed(startTime, endTime) << " seconds" << std::endl;


	return 0;
}
