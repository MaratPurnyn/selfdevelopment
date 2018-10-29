import bisect
#implementation of the Bentley Ottman Algorithm for detecting intersections in O(NLogN+k)
class Event:
    p1 = (0,0) #point (y,x)
    p2 = (0,0) 
    event_type = None #'start', 'end', and 'v' are accepted types
    
    def __init__(self, p1, p2, event_type):
        self.p1 = p1
        self.p2 = p2
        self.event_type = event_type

def find_intersections(segments):
    # create list of events
    events = [] #list of events (point, type of event)
    cnt = 0
    for seg in segments:
        p1x = seg[0][0]
        p1y = seg[0][1]
        p2x = seg[1][0]
        p2y = seg[1][1]
        cnt = cnt + 1
        if(p1x == p2x):
            # add vertical segments to event list
            events.append(Event((p1y,p1x),(p2y,p2x), 'v'))
        else:
            # add horizontal segments to event list 
            events.append(Event((p1y,p1x),(p2y,p2x), "start"))
            events.append(Event((p2y,p2x),(p1y,p1x), "end"))
    events.sort(key=lambda e: (e.p1[1],e.p1[0]))

    #find intersections by iterating thru events
    s = [] # set of horizontal segments
    intersections = [] # list of intersection points
    for e in events:
        # if the e is the start of horizontal segment, add it
        # if the e is the end, remove it
        # if a segment is present when e is a  vertical segment, that's your intersection.
        if(e.event_type == 'start'): 
            s.append(e.p1) 
        elif(e.event_type == 'end'): 
            s.remove(e.p2)
        else:
            #remove segments less than y range
            lower_cut_point = (e.p2[0], -1)
            upper_cut_point = (e.p1[0], -1)
            lower_bound = bisect.bisect_left(s, lower_cut_point)
            upper_bound = bisect.bisect_right(s[lower_bound:], upper_cut_point)
            #only check segments in y range
            for p in s[lower_bound:upper_bound]:
                intersections.append((e.p1[1], p[0]))
    return intersections