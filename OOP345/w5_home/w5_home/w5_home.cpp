// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/17 , 2019
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
                       const Book& theBook)
{
    std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
                        const Movie& theMovie)
{
    std::cout << "Movie \"" << theMovie.title()
    << "\" added to collection \"" << theCollection.name()
    << "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";
    
    // get the book
    sdds::Collection<sdds::Book> library("Bestsellers");
    {
            size_t cnt = 0;
            std::ifstream file(argv[1]);
            if (!file)
            {
                std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
                return 1;
            }
            std::string strBook;
            Book temp[7];
            do {
                std::getline(file, strBook);
                if (strBook[0] != '#'){
                    temp[cnt] = strBook;
                    library += temp[cnt];
                    cnt++;
                }
            } while ( cnt <  4 );
        
        
        library.setObserver(bookAddedObserver);
        // TODO: add the rest of the books from the file.
        do{
            std::getline(file,strBook);
            if(strBook[0] != '#'){
                temp[cnt] = strBook;
                library += temp[cnt];
                cnt++;
            }
        }while(cnt < 7);
        
        file.close();
    }
    
    
    double usdToCadRate = 1.3;
    double gbpToCadRate = 1.5;
    auto update = [=](sdds::Book& rhs)  {
        std::string nation = rhs.country();
        size_t yr = rhs.year();
        if (nation == "US") {
            rhs.price() *= usdToCadRate;
        }
        else if( nation == "UK" && yr >= 1990 && yr <= 1999 ){
            rhs.price() *= gbpToCadRate;
        }
        return rhs.price();
    };
    
    
    std::cout << "-----------------------------------------\n";
    std::cout << "The library content\n";
    std::cout << "-----------------------------------------\n";
    std::cout << library ;
    std::cout << "-----------------------------------------\n\n";
    
    // TODO (from in-lab): iterate over the library and update the price of each book
    //         using the lambda defined above.
    for ( size_t i = 0  ; i < library.size() ;i++)
        update(library[i]);
    
    
    std::cout << "-----------------------------------------\n";
    std::cout << "The library content (updated prices)\n";
    std::cout << "-----------------------------------------\n";
    std::cout << library;
    std::cout << "-----------------------------------------\n\n";
    
    Collection<Movie> theCollection("Action Movies");
    
    // Process the file
    Movie movies[5];
    {
        // TODO: load 5 movies from the file "argv[2]".
        //       - read one line at a time, and pass it to the Movie constructor
        //       - store each movie read into the array "movies"
        //       - lines that start with "#" are considered comments and should be ignored
        auto cnt = 0;
        {
            std::ifstream file(argv[2]);
            if (!file)
            {
                std::cerr << "ERROR: Cannot open file [" << argv[2] << "].\n";
                return 1;
            }
            
            std::string strMoive = "";
            do {
                getline(file, strMoive);
                if (strMoive[0] != '#'){
                    movies[cnt] = strMoive;
                    cnt++;
                }
            } while (cnt < 5 );
        }
    }
        
        
        
        std::cout << "-----------------------------------------\n";
        std::cout << "Testing addition and callback function\n";
        std::cout << "-----------------------------------------\n";
        // Add a few movies to collection; no observer is set
        ((theCollection += movies[0]) += movies[1]) += movies[2];
        theCollection += movies[1];
        // add more movies; now we get a callback from the collection
        theCollection.setObserver(movieAddedObserver);
        theCollection += movies[3];
        theCollection += movies[3];
        theCollection += movies[4];
        std::cout << "-----------------------------------------\n\n";
        
        std::cout << "-----------------------------------------\n";
        std::cout << "Testing exceptions and operator[]\n";
        std::cout << "-----------------------------------------\n";
        
        // TODO: The following loop can generate generate an exception
        //         write code to handle the exception
        //       If an exception occurs print a message in the following format
        //EXCEPTION: ERROR_MESSAGE<endl>
        //         where ERROR_MESSAGE is extracted from the exception object.
    try{
        for ( auto i = 0 ; i < 10 ;i++)
            std::cout<< theCollection[i];
    }
    catch( const std::out_of_range& err){
        std::cout << "EXCEPTION: " << err.what() << std::endl;
    }

        std::cout << "-----------------------------------------\n\n";
        
        
        std::cout << "-----------------------------------------\n";
        std::cout << "Testing the functor\n";
        std::cout << "-----------------------------------------\n";
        for (auto i = 3u; i <= 4u; ++i)
        {
            // TODO: The following statement can generate generate an exception
            //         write code to handle the exception
            //       If an exception occurs print a message in the following format
            //EXCEPTION: ERROR_MESSAGE<endl>
            //         where ERROR_MESSAGE is extracted from the exception object.
            try{
                SpellChecker sp(argv[i]);
                for (auto j = 0u; j < theCollection.size(); ++j)
                    theCollection[j].fixSpelling(sp);
                for (auto j = 0u; j < library.size(); ++j)
                    library[j].fixSpelling(sp);
            }
            catch( const char* err2){
                std::cout << "EXCEPTION: " << err2 << std::endl;
            }
            
        }
        std::cout << "--------------- Movies ------------------\n";
        std::cout << theCollection ;
        std::cout << "--------------- Books -------------------\n";
        std::cout << library;
        std::cout << "-----------------------------------------\n\n";
        
        
        std::cout << "-----------------------------------------\n";
        std::cout << "Testing operator[] (the other overload)\n";
        std::cout << "-----------------------------------------\n";
        const Movie* aMovie = theCollection["Terminator 2"];
        if (aMovie == nullptr)
            std::cout << "Movie Terminator 2 not in collection.\n";
        aMovie = theCollection["Dark Phoenix"];
        if (aMovie != nullptr)
            std::cout << "In collection:\n" << *aMovie;
        std::cout << "-----------------------------------------\n\n";
        
        return 0;
    }
