//return the highest value in a 2D int array, if no values error
	public static int max( int[][] arr ){		
		int temp, ret = 0; //compile error if ret not initialized
		boolean retInit = false, allEmpty = true;

		for( int i = 0; i < arr.length; i++){
			
			//check if array index is null or empty
			if( arr[i] != null && arr[i].length > 0 ){
				temp = arr[i][0];
				for( int j = 0; j < arr[i].length; j++){
					if ( temp < arr[i][j])
						temp = arr[i][j];
				}
				
				//if no value in ret yet
				if( !retInit ){
					ret = temp;
					retInit = true;
				}
				//if ret already has a value
				else if ( ret < temp )
					ret = temp;
				
				//mark when at least 1 array isnt null or empty
				if( allEmpty )
					allEmpty = false;
			}
		}
		
		//if all were null or empty
		if( allEmpty )
			error( "All values were null or empty.");
		
		return ret;
	}