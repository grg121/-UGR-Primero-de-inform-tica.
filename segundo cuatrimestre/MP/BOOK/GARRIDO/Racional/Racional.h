
  Class Racional {
	int num, den ; 
	void normalizar(){
		int minimo = num<den?num:den ; 
		for(int i = 2 ; i < minimo ; i++){
			if( i % num == 0 && i % den == 0){
				num = num/i ;
				den = den/i ;
			}
		}
 
		if(den < 0){
			den = den * -1 ;
			num = num * -1 ; 
		
