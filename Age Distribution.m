#import <Foundation/Foundation.h>


NSString* getDistribution(NSString *line) {
    NSString *tmp;
    int tmpInt = [tmp intValue];
   
    
    return tmp;
}


int main(int argc, const char * argv[])
{

    @autoreleasepool {
        NSString *filename = [NSString stringWithCString:argv[1] encoding:NSASCIIStringEncoding];
        NSString *content = [NSString stringWithContentsOfFile:filename encoding:NSASCIIStringEncoding error:nil];
        NSArray *lines = [content componentsSeparatedByString:@"\n"];
    }
    return 0;
}

