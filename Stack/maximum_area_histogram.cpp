class Solution
{

public:
int largestRectangleArea (vector < int >&heights)
  {
    
int i = 0;
     
long int tp, area = 0, max = 0;
     
stack < long int >s;
     
long int n = heights.size ();
     
while (i < n)
      {
	
if (s.empty () || heights[s.top ()] <= heights[i])
	  {
	    
s.push (i++);	//if array is empty or further elements are greater, keep pushing untill we find next smaller
	  
}
	 
	else
	  {			//else go back and keep finding area of rectangle relative to each element
	    tp = s.top ();
	    
s.pop ();
	    
area = heights[tp] * (s.empty ()? i : i - s.top () - 1);	//if stack empty,keep only that element area else all rectangle coming in between
	    if (area > max)
	      {
		
max = area;
	      
}
	  
 
}
      
}
    
while (s.empty () == false)
      {				//if some elments left in stack
	tp = s.top ();
	
s.pop ();
	
area = heights[tp] * (s.empty ()? i : i - s.top () - 1);
	
if (area > max)
	  {
	    
max = area;
	  
}
      
}
    
return max;
  
}

 
};
