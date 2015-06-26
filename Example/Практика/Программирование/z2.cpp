// Compile flags: -Wall -std=c++11

#include <iostream>
#include <valarray>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector< double > array_t;

void input_array( array_t& array );
void print_array( array_t& array );
double calculate_sum_of_positive( array_t& array );
double calculate_multiplication_betwen_min_and_max( array_t& array );

int main( int argc, const char* argv[ ] )
{
  array_t array;
  input_array( array );
  std::cout << "Array:\n";
  print_array( array );
  std::cout << "Sum of positive values is "
    << calculate_sum_of_positive( array );
  std::cout << "\nMultiplication betwen min abs and max abs is "
    << calculate_multiplication_betwen_min_and_max( array );
  return 0;
}



void input_array( array_t& array )
{
  std::string user_input;
  
  std::cout << "Enter new values. Leave line empty to finish.\n";
  while( true ) {
    std::cout << "Enter value > ";
    std::getline( std::cin, user_input );
  
    double value;
  
    try {
      value = std::stod( user_input );
    }
    catch( std::exception& exception ) {
      std::cout << "Construction of the array complete.\n";
      return;
    }
    
    std::cout << "Add to array: " << value << "\n";
    array.push_back( value );
  }
}

void print_array( array_t& array )
{
  for( auto const& value : array ) {
    std::cout << value << ' ';
  }
  std::cout << '\n';
}

double calculate_sum_of_positive( array_t& array )
{
  double sum = 0;
  for( auto const& value : array ) {
    if( value > 0 ) {
      sum += value;
    }
  }
  return sum;
}

double calculate_multiplication_betwen_min_and_max( array_t& array )
{  
  if( array.empty() ) {
    return 0;
  }
  
  auto it_min = array.begin();
  auto it_max = array.begin();
  for( auto it = array.begin(); it != array.end(); ++it ) {
    if( std::abs( *it ) < std::abs( *it_min ) ) {
      std::swap( it_min, it );
    }
    if( std::abs( *it ) > std::abs( *it_max ) ) {
      std::swap( it_max, it );
    }
  }
  
  if( it_min > it_max ) {
    std::swap( it_min, it_max );
  }
  
  double multiplication = 1;  
  for( array_t::iterator it = it_min; it != it_max + 1; ++it ) {
    multiplication *= *it;
  }
  
  return multiplication;
}
