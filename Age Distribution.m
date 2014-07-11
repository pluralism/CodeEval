#import <Foundation/Foundation.h>


NSString* getDistribution(NSString *line) {
    int tmpInt = [line intValue];
    
    if(tmpInt < 0 || tmpInt > 100)
        return @"This program is for humans";
    else if(tmpInt >= 66)
        return @"Retirement";
    else if(tmpInt >= 23)
        return @"Work";
    else if(tmpInt >= 19)
        return @"College";
    else if(tmpInt >= 15)
        return @"High school";
    else if(tmpInt >= 12)
        return @"Middle school";
    else if(tmpInt >= 5)
        return @"Elementary school";
    else if(tmpInt >= 3)
        return @"Preschool";
    else if(tmpInt >= 0)
        return @"Home";
    
    return nil;
}


int main(int argc, const char * argv[])
{

    @autoreleasepool {
        NSString *filename = [NSString stringWithCString:argv[1] encoding:NSASCIIStringEncoding];
        NSString *content = [NSString stringWithContentsOfFile:filename encoding:NSASCIIStringEncoding error:nil];
        NSArray *lines = [content componentsSeparatedByString:@"\n"];
        
        for(NSString *line in lines) {
            NSString *tmp = getDistribution(line);
            NSLog(@"%@", tmp);
        }
    }
    return 0;
}

