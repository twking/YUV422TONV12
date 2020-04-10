void yuyv_to_nv12(uint8_t * image_in, uint8_t* image_out, int width, int height, unsigned long int filesize)
  {


	unsigned int pixNUM = (width<<1);	  
	unsigned int j =0,k =0;
	
	uint8_t *uv=image_out + width*height;
	uint8_t *u8start=image_in-(width<<1);
	uint8_t *y = image_out;
	uint16_t *u16start;
	
	pixNUM = pixNUM-16;
	for(j=0; j< height; j+=2)  //
	{
		//偶数行 提取 Y，UV
		u8start += (width<<1);
		for(k = 0; k<pixNUM; k=k+16)    //YUYV
		{
			*y++ = *u8start++;
			*uv++= *u8start++;
			*y++ = *u8start++;
			*uv++ = *u8start++//4

			*y++ = *u8start++;
			*uv++= *u8start++;
			*y++ = *u8start++;
			*uv++ = *u8start++//8
			
			*y++ = *u8start++;
			*uv++= *u8start++;
			*y++ = *u8start++;
			*uv++ = *u8start++//12
			
			*y++ = *u8start++;
			*uv++= *u8start++;
			*y++ =  *u8start++;
			*uv++ = *u8start++//16
		}
		for(; k< pixNUM+16; k=k+4)    //YUYV
		{
			*y++ = *u8start++;
			*uv++= *u8start++;
			*y++ = *u8start++;
			*uv++= *u8start++
			
		}
		
		//奇数数行提取 Y
		u16start = (uint16_t *)u8start;
		for(k = 0; k<width-8; k=k+8)    //YUYV
		{
			*y++= *u16start++;
			*y++= *u16start++;
			*y++= *u16start++;
			*y++= *u16start++;//4			
			*y++= *u16start++;
			*y++= *u16start++;			
			*y++= *u16start++;
			*y++= *u16start++;//8
		}
		for(; k< width; k++)    //YUYV
		{
			*y++= *u16start++;
			
		}
	} 

 }
