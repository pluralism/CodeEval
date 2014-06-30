#import <Foundation/Foundation.h>


int number_of_bats(int start, int end, int spacing, bool cond) {
    if(cond)
        return (end - start) / spacing - 1;
    return (end - start) / spacing;
}


void calculate(NSArray *elements) {
    int start = 6,
        final = [elements[0] intValue] - 6,
        spacing_between_bats = [elements[1] intValue],
        total_bats = 0,
        bats_on_wire = [elements[2] intValue];
    
    if(bats_on_wire > 1) {
        total_bats += number_of_bats(start, [elements[3] intValue], spacing_between_bats, false);
        for(int i = 3; i < [elements count] - 1; i++)
            total_bats += number_of_bats([elements[i] intValue], [elements[i + 1] intValue], spacing_between_bats, true);
        total_bats += number_of_bats([elements[[elements count] - 1] intValue], final, spacing_between_bats, false);
        
        NSLog(@"%d", total_bats < 0 ? 0 : total_bats);
    } else if(bats_on_wire == 1) {
        total_bats += number_of_bats(start, [elements[3] intValue], spacing_between_bats, false);
        total_bats += number_of_bats([elements[3] intValue], final, spacing_between_bats, false);
        NSLog(@"%d", total_bats < 0 ? 0 : total_bats);
    } else if(bats_on_wire == 0)
        NSLog(@"%d", (final - start) / spacing_between_bats + 1);
}


int main(int argc, const char * argv[])
{
    @autoreleasepool {
        NSString *filename = [NSString stringWithCString:argv[1] encoding:NSASCIIStringEncoding];
        
        NSString *content = [NSString stringWithContentsOfFile:filename encoding:NSASCIIStringEncoding error:nil];
        
        NSArray *lines = [content componentsSeparatedByString:@"\n"];
        for(NSString *line in lines) {
            NSArray *elements = [line componentsSeparatedByString:@" "];
            calculate(elements);
        }
    }
    
    return 0;
}

