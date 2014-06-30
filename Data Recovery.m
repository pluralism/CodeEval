#import <Foundation/Foundation.h>


NSInteger intSort(id num1, id num2, void *context) {
    int v1 = [num1 intValue];
    int v2 = [num2 intValue];
    
    if(v1 < v2)
        return NSOrderedAscending;
    else if(v1 > v2)
        return NSOrderedDescending;
    else
        return NSOrderedSame;
}


void performAction(NSString *line) {
    NSArray *array = [line componentsSeparatedByString:@";"];
    NSArray *words = [array[0] componentsSeparatedByString:@" "];
    NSArray *index = [array[1] componentsSeparatedByString:@" "];
    
    
    NSMutableDictionary *dictionary = [NSMutableDictionary dictionaryWithDictionary:@{}];
    for(int i = 0; i < [index count]; i++)
        [dictionary setObject:words[i] forKey:index[i]];
    
    
    NSArray *sortedKeys = [[dictionary allKeys] sortedArrayUsingFunction:intSort context:nil];
    for(int i = 0; i < [words count]; i++) {
        NSString *val = [dictionary valueForKeyPath:[NSString stringWithFormat:@"%d", i + 1]];
        if(val == NULL)
            [dictionary setObject:words[[words count] - 1] forKey:[NSString stringWithFormat:@"%d", i + 1]];
    }
    
    
    sortedKeys = [[dictionary allKeys] sortedArrayUsingFunction:intSort context:nil];
    NSMutableArray *sortedValues = [NSMutableArray array];
    for(NSString *key in sortedKeys)
        [sortedValues addObject:[dictionary objectForKey:key]];
    NSString *finalString = [sortedValues componentsJoinedByString:@" "];
    NSLog(@"%@", finalString);
}



int main(int argc, const char * argv[])
{

    @autoreleasepool {
        NSString *filename = [NSString stringWithCString:argv[1] encoding:NSASCIIStringEncoding];
        NSString *content = [NSString stringWithContentsOfFile:filename encoding:NSASCIIStringEncoding error:nil];
        NSArray *lines = [content componentsSeparatedByString:@"\n"];
        for(NSString *line in lines)
            performAction(line);
    }
    return 0;
}